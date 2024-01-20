#include "functions.h"


std::vector<std::string> splitString(const std::string& input, char delimiter=' ') {

    std::vector<std::string> values;
    std::istringstream stream (input);
    std::string value;
    
    while (std::getline(stream, value, delimiter)) {
        values.push_back(value);
    }

    return values;
}


void getFirstParams (std::string in, int& size, std::vector<int>& hashTimes) {

    // split the string to its values
    std::vector<std::string> inputVals = splitString(in, ' ');
    
    // set the size of the bloomfilter
    size = std::stoi(inputVals[0]);

    // go from first place in array onwards, and copy.
    for (auto it = inputVals.begin()+1; it != inputVals.end(); it++) {
        hashTimes.push_back(std::stoi(*it));
    }
}


bool checkIs1URLOr2URL (std::string in) { // TEST WRITTEN

   // split the string to its values
    std::vector<std::string> inputVals = splitString(in, ' ');
    
    // get first int
    int n = std::stoi(inputVals[0]);

    if ( 1 > n || n > 2 || inputVals.size() > 2) {
        return false;
    }

    // we get any string as URL
    return true;
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
        // works for very large nums, checks str as long long.
        if (std::stoll(val) > MAXBLOOMSIZE){
            return false;
        }
    }
    
    return true;
}


void addToBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom) {
    
    // this will be the output of hashing i times
    std::string prevHash;

    for (int repeatTimes : hashTimes) {

        prevHash = "";

        // hash i times the url
        for (int j = 0; j < repeatTimes; j++)
        {
            // we convert it to str as h only accepts strs as params
            prevHash = std::to_string(h((prevHash == "") ? url : prevHash));           
        }
        
        // string to long long
        bloom[stoll(prevHash) % bloom.size()] = 1;
    }
}


bool checkInBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom) {
    
    // this will be the output of hashing i times
    std::string prevHash;

    for (int repeatTimes : hashTimes) {

        prevHash = "";

        // hash i times the url
        for (int j = 0; j < repeatTimes; j++)
        {
            // we convert it to str as h only accepts strs as params
            prevHash = std::to_string(h((prevHash == "") ? url : prevHash));           
        }
        
        // string to long long
        if (bloom[stoll(prevHash) % bloom.size()] != 1) { return false; };
    }

    return true;
}


void addToBlackList (std::string hash) { // DOESNT NEED TEST
    std::fstream file;
    // we need both ios::out and ios::trunc
    file.open("blacklist.txt", std::ios::out | std::ios::trunc);
    file.close();
}


bool checkInBlackList (std::string in) {
    //     std::fstream file;
    // // we need both ios::out and ios::trunc
    // file.open("blacklist.txt", std::ios::out | std::ios::trunc);
    
    // file.close();

    std::fstream inputFile("blacklist.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        // every URL is in a separate line
        if (in == line){
            inputFile.close();
            return true;
        }
    }
    inputFile.close();
    return false;
}

