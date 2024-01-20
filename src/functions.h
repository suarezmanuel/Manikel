#ifndef shmulik

#define shmulik

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

void addToBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom);

bool checkInBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom);

void addToBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom);

bool checkInBloom(const std::hash<std::string> h, const std::string url, std::vector<int>& hashTimes, std::vector<bool>& bloom);

bool addToBlackList (std::string url);

bool checkIfInBlackList (std::string url);

#endif