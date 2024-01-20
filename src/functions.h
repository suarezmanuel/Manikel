#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

#define MAXBLOOMSIZE 1248

std::vector<std::string> splitString(const std::string& input, char delimiter);

void getFirstParams (std::string in, int& size, std::vector<int>& hashTimes);

bool checkIs1URLOr2URL (std::string in);

bool checkInputFormatFirstParams (std::string str);

void addToBlackList (std::string hash);

bool checkInBlackList (std::string in);

bool checkFalsePos (std::string in);