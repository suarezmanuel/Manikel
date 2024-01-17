#include <gtest/gtest.h>
#include "../src/main.cpp"


TEST (InputTest, BasicTest) {
    EXPECT_EQ(checkInputFormatURLS("1 www.example.com0"), true); // valid number and url
    EXPECT_EQ(checkInputFormatURLS("2 www.example.com0"), true); // valid number and url
    EXPECT_EQ(checkInputFormatURLS("3 www.example.com0"), false); // invalid number but valid url
    EXPECT_EQ(checkInputFormatURLS("1 eweq"), false); // valid number but invalid url
    EXPECT_EQ(checkInputFormatURLS("3 eweq"), false); // invalid number and url

    EXPECT_EQ(is1URL("1"), true); // valid number
    EXPECT_EQ(is1URL("2"), false); // invalid number
    EXPECT_EQ(is1URL("a"), false); // invalid number
    
    EXPECT_EQ(checkInBlackList("www.example.com0"), true); // valid url
    EXPECT_EQ(checkInBlackList("www.NotInBlackList.com0"), false);// url that is not in blacklist
    EXPECT_EQ(checkInBlackList("asdas"), false);// invalid url

    EXPECT_EQ(checkInputFormatFirstParams("128 1 2"), true);
    EXPECT_EQ(checkInputFormatFirstParams("128 asdsad"), false);
    EXPECT_EQ(checkInputFormatFirstParams("asdsda"), false);
    EXPECT_EQ(getFirstParams());
    EXPECT_EQ(checkFalsePos(), true);
}
