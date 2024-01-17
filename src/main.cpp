#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// change size, count inside func. x y z w ... where x denotes bloom size,
// y: how many hashes for y hash, w: how many hashes for w hash...
void getFirstParams (std::string in, int& size, std::vector<int>& hashes);
// check for either: 1/2 URL, or x y z w ... (getFirstParams)
bool checkInputFormatURLS (std::string in);
bool checkInputFormatFirstParams (std::string in);
bool is1URL (std::string in);
void addToBlackList (std::string hash) {

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
    std::vector<int> hashes;
    std::vector<int> hashes;
    
    
    while (true) {

        // first line, bloom size, hashes
        std::getline(std::cin, in);

        if (checkInputFormatURLS(in)) {

            if (is1URL(in)) {
                addToBlackList(in);
            // must be 2URL
            } else {
                if(checkInBlackList(in)) { checkFalsePos(in) }
            }
        
        // 123 2 2 2 2 2 2 2 2 
        } else if (checkInputFormatFirstParams(in)) {
            getFirstParams(in, bloomSize, hashes);
        }

        bloomSize = 0;
        hashes.clear();
    }
}