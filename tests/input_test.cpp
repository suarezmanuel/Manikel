#include <gtest/gtest.h>
#include "../src/calc.cpp"

TEST (InputTest, BasicTest) {
    EXPECT_EQ(checkInputFormat(std::string a), True);
    EXPECT_EQ(is1URL(std::string a), True);
    EXPECT_EQ(is2URL(std::string a), True);
    EXPECT_EQ(addToBlackList(std::string a));
    EXPECT_EQ(checkInBlackList(std::string a), True);
    EXPECT_EQ(checkInBlackList(std::string a), True);
    EXPECT_EQ(getFirstParams(std::string in, int& size, std::vector<int>& hashes));
    EXPECT_EQ(checkFalsePos(std::string a), True);
}
