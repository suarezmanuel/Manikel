#include <iostream>
#include <string>

bool getFirstParams (std::string a, int& size, int count);
bool is1URL (std::string a);
bool is2URL (std::string a);
bool addToBlackList (std::string a);
bool checkInBlackList (std::string a);
bool checkFalsePos (std::string a);

int main () {
    std::string a;
    // size in bits
    int bloomSize;
    int funcCount;
    while (true) {
        // ignore bad input format.

        // first line, bloom size, hashes
         std::getline(std::cin, a);
         getFirstParams (a, bloomSize, funcCount)

        // other lines
        if (is1URL(a)) { addToBlackList(a); }
        else {
            if (is2URL(a)) { if(checkInBlackList(a)) { checkFalsePos(a) } }
        }

    }
}