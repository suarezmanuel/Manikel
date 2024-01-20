#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <fstream>
#include <regex>

#define MAXBLOOMSIZE 1248

// Function to split a string based on a delimiter
std::vector<std::string> splitString(const std::string& input, char delimiter) {

    std::vector<std::string> values;
    std::istringstream stream(input);
    std::string value;
    
    while (std::getline(stream, value, delimiter)) {
        values.push_back(value);
    }

    return values;
}


// change size, count inside func. x y z w ... where x denotes bloom size,
// y: run y times the hash, w: run w times the hash... DOESNT NEED TEST
void getFirstParams (std::string in, int& size, std::vector<int>& hashTimes) {

    // split the string to its values
    std::vector<std::string> inputVals = splitString(in, ' ');
    
    // set the size of the bloomfilter
    size = std::stoi(inputVals[0]);
    
    // copy the splitted int values for hashes (index 1, onwards) from tokens to hashTimes
    std::copy(inputVals.begin()+1, inputVals.end(), std::back_inserter(hashTimes));
}


bool checkIs1URLOr2URL (std::string in) { // TEST WRITTEN

   // split the string to its values
    std::vector<std::string> inputVals = splitString(in, ' ');
    
    // get first int
    int n = std::stoi(inputVals[0]);

    std::string s = inputVals[1];

    if ( 1 > n || n > 2 || inputVals.size() > 2) {
        return false;
    }

    // we discriminate all URLS except the ones coming from the domains www and .com
    std::regex r ("www\\.(\\w+)\\.com");
} 


bool checkInputFormatFirstParams (std::string str) { // TEST WRITTEN
    // checks if the string contains only digits
    for (char c : str) 
    {
        if (c != ' ' && (c > '9' || c < '0')) {
            return false;
        }
    }

    // split the string to its values
    std::vector<std::string> inputVals = splitString(str, ' ');

    // checks if the digits are valid (not bigger then the max_size)
    for (std::string val: inputVals) {  
        if (std::stoi(val) > MAXBLOOMSIZE){
            return false;
        }
    }
    
    return true;
}

void addToBlackList (std::string hash) { // DOESNT NEED TEST

    std::fstream file;
    // we need both ios::out and ios::trunc
    file.open("blacklist.txt", std::ios::out | std::ios::trunc);
    // file.open("blacklist.txt", std::ios::app);
    // file << " i";
    file.close();
}

bool checkInBlackList (std::string in) {
    
}

bool checkFalsePos (std::string in) {
    
}


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


