#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "src/functions.h"
#include <stdint.h>
#include <mutex>
#include <atomic>

#define PORT 4111
#define BUFFER_SIZE 1024

bool isBloomInitialized = false;

// after init we only read from these
std::hash<std::string> hash;
std::vector<bool> bloom; 
std::vector<int> hashTimes;

std::atomic<bool> isHashInit;
std::mutex mutex;


void* handleClient(void* arg) {
    // Receive and echo back the client's messages
    char input[BUFFER_SIZE];
    std::string out = "";
    bool gotFirstParams = false;
    int bloomSize = 0;
    int client_sock = (uintptr_t)arg;

    bool firstLoop = true;

    while (true) {

        // Echo the message back to the client
        // std::cout << out << std::endl;
        if (!firstLoop && (send(client_sock, out.c_str(), out.length(), 0) < 0)) {
            std::cerr << "Error sending message" << std::endl;
            break;
        }

        firstLoop = false;

        // first line, bloom size, hashes
        memset(input, '\0', sizeof(input));
        out = "";

        int recvBytes = recv(client_sock, input, sizeof(input), 0);
        std::string in = std::string(input);
        stripRight(in);
        // std::cout << "\"" << in << "\"" << std::endl;

        if (recvBytes < 0) {
            std::cout << "Error receiving message" << std::endl;
            break;
        } else if (recvBytes == 0) {
            std::cout << "client disconnected" << std::endl;
            break;
        }

        // if bloom isnt initialized
        if (isHashInit.load() == false && checkInputFormatFirstParams(in)) {
            // init bloom
            getFirstParams(in, bloomSize, hashTimes);
            bloom.insert(bloom.end(), bloomSize, false);

            isHashInit = true;
            out = "initialized bloom filter";
            continue;
        }

        if (isHashInit.load() == false) {
            out = "bloom filter is yet to be initialized";
            continue;
        }

        if (!checkIs1URLOr2URL(in)) {
            out = "incorrect input format";
            continue;
        }

        mutex.lock();

        // url format is correct, we already checked it
        std::vector<std::string> input = splitString(in, ' ');

        if (input[0] == "1") { 
            // input[1] is our beloved URL
            addToBloom(hash, input[1], hashTimes, bloom);
            addToBlackList(input[1]);

            out = "added URL to bloomfilter"; 
        // must start with 2
        } else {
            
            bool check = checkInBloom(hash, input[1], hashTimes, bloom);
            out = (check ? "true" : "false");

            if (check) { 
                out = out + " " + (checkIfInBlackList(input[1]) ? "true" : "false"); 
            }
        }

        mutex.unlock();
    }

    // Clean up
    close(client_sock);
    return nullptr;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    // reset blacklist.txt
    remove("blacklist.txt");
    std::ofstream file("blacklist.txt", std::ios::app);
    file.close();

    std::cout << "initialized the blacklist" << std::endl;


    // Accept incoming connections and handle them in separate threads
    while (true) {
        struct sockaddr_in clientAddr;
        unsigned int addrLen = sizeof(clientAddr);
        int clientSock = accept(sock, (struct sockaddr*)&clientAddr, &addrLen);
        if (clientSock < 0) {
            std::cerr << "Error accepting connection" << std::endl;
            continue;
        }

        std::cout << "new client connected" << std::endl;
        pthread_t thread;
        pthread_attr_t a;
        pthread_attr_init(&a);
        pthread_create(&thread, &a, handleClient, (void*)(uintptr_t)clientSock);
        // t.detach();
    }

    close(sock);
    return 0;
}
