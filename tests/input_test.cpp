#include <gtest/gtest.h>
#include "../src/main.cpp"

TEST (InputTest, FirstParamsTest) {
    EXPECT_EQ(checkInputFormatFirstParams("128 1 2"), true);
    EXPECT_EQ(checkInputFormatFirstParams("1231212124124 1 1"), false);
    // EXPECT_EQ(checkInputFormatFirstParams("1231212124124 1 1"), fa);
    EXPECT_EQ(checkInputFormatFirstParams("1124124 0 1"), false);
    EXPECT_EQ(checkInputFormatFirstParams("1124124 1 0"), false);
    EXPECT_EQ(checkInputFormatFirstParams("1124124 0 0"), false);
    // EXPECT_EQ(checkInputFormatFirstParams("128 1 2"), true);
    EXPECT_EQ(checkInputFormatFirstParams("128 asdsad"), false);
    EXPECT_EQ(checkInputFormatFirstParams("asdsda"), false);
}

TEST (InputTest, IsURLTest) {
    EXPECT_EQ(checkIs1URLOr2URL("1 www.example.com0"), true); // valid number and url
    EXPECT_EQ(checkIs1URLOr2URL("2 www.example.com0"), true); // valid number and url
    EXPECT_EQ(checkIs1URLOr2URL("3 www.example.com0"), false); // invalid number but valid url
    EXPECT_EQ(checkIs1URLOr2URL("1 eweq"), false); // valid number but invalid url
    EXPECT_EQ(checkIs1URLOr2URL("3 eweq"), false); // invalid number and url
}    

TEST (InputTest, CheckBlackListTest) {
    // addToBlackList("www.example.com0");
    EXPECT_EQ(checkInBlackList("www.example.com0"), true); // check if adding worked

    EXPECT_EQ(checkInBlackList("www.NotInBlackList.com0"), false);// url that is not in blacklist
}

// TEST (InputTest, CheckFalsePos) {

// }

