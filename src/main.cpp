#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <fstream>

// change size, count inside func. x y z w ... where x denotes bloom size,
// y: run y times the hash, w: run w times the hash...
void getFirstParams (std::string in, int& size, std::hash<std::string> hash); // DOESNT NEED TEST
// check for either: 1/2 URL, or x y z w ... (getFirstParams)

bool checkIs1URLOr2URL (std::string in); // TEST WRITTEN
bool checkInputFormatFirstParams (std::string in); // TEST WRITTEN

void addToBlackList (std::string hash) { // DOESNT NEED TEST

    std::fstream file;
    // we need both ios::out and ios::trunc
    file.open("blacklist.txt", std::ios::out | std::ios::trunc);
    // file.open("blacklist.txt", std::ios::app);
    // file << " i";
    file.close();
}

bool checkInBlackList (std::string in);
bool checkFalsePos (std::string in);


int main () {
    std::string in;
    // size in bits
    int bloomSize;
    std::hash<std::string> hashes;
    bool gotFirstParams = false;
    
    while (true) {

        // first line, bloom size, hashes
        std::getline(std::cin, in);


        if (checkInputFormatFirstParams(in)) {
            getFirstParams(in, bloomSize, hashes);
            gotFirstParams = true;
        }
        

        if (gotFirstParams && checkIs1URLOr2URL(in)) {

            if (in[0] == '1') {
                addToBlackList(in);

            // must start with 2
            } else {
                bool check = checkInBlackList(in);
                std::cout << check; 
                
                if (check) { 
                    std::cout << " " << checkFalsePos(in) << std::endl;
                } else {
                    std::cout << std::endl;
                }
            }
        }
    }
}