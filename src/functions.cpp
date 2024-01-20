#include "functions.h"


std::vector<std::string> splitString(const std::string& input, char delimiter) {

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

    std::string s = inputVals[1];

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
        if (std::stoi(val) > MAXBLOOMSIZE){
            return false;
        }
    }
    
    return true;
}


bool addToBlackList (std::string url) { // DOESNT NEED TEST
    // Open a file for writing
    std::ofstream outputFile("blacklist.txt", std::ios::app);

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        // std::cerr << "Error opening the file." << std::endl;
        return false; // Return an error code
    }

    // Write data to the file
    outputFile << url << std::endl;

    // Close the file
    outputFile.close();
    return true;
}


bool checkInBlackList (std::string in) {
    //     std::fstream file;
    // // we need both ios::out and ios::trunc
    // file.open("blacklist.txt", std::ios::out | std::ios::trunc);
    
    // file.close();
    return true;
}


bool checkFalsePos (std::string in) {

    std::fstream inputFile("blacklist.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        if(in == line){
            inputFile.close();
            return true;
        }
    }
    inputFile.close();
    return false;
}