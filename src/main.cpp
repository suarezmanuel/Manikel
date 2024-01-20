#include <iostream>
#include "functions.h"

int main () {

    // size in bits
    bool gotFirstParams = false;
    int bloomSize = 0;
    std::string in;
    std::hash<char> hash;
    std::vector<bool> bloom; 
    std::vector<int> hashTimes;
    
    while (true) {

        // first line, bloom size, hashes
        std::getline(std::cin, in);


        if (checkInputFormatFirstParams(in) && !gotFirstParams) {
            getFirstParams(in, bloomSize, hashTimes);
            bloom.insert(bloom.end(), bloomSize, false);
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


