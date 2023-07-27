#include "pch.h"
#include <Utility/StringUtility.h>

    // StringUtility::Split()のテスト
TEST(StringUtilityTests, SplitTest) {
    // テストケース1: 区切り文字がスラッシュの場合
    std::string text1 = "one/two/three/four";
    char delim1 = '/';
    std::vector<std::string> expected1 = { "one", "two", "three", "four" };
    EXPECT_EQ(PotatoLib::StringUtility::Split(text1, delim1), expected1);

    // テストケース2: 区切り文字がバックスラッシュの場合
    std::string text2 = "a\\b\\c\\d";
    char delim2 = '\\';
    std::vector<std::string> expected2 = { "a", "b", "c", "d" };
    EXPECT_EQ(PotatoLib::StringUtility::Split(text2, delim2), expected2);

    // テストケース3: パスにスラッシュとバックスラッシュが混在した場合
    std::string text3 = "x\\y/z\\w";
    char delim3 = '/';
    std::vector<std::string> expected3 = { "x\\y", "z\\w" };
    EXPECT_EQ(PotatoLib::StringUtility::Split(text3, delim3), expected3);

    // テストケース4: テキストが空文字列の場合
    std::string text4 = "";
    char delim4 = '/';
    std::vector<std::string> expected4 = {};
    EXPECT_EQ(PotatoLib::StringUtility::Split(text4, delim4), expected4);
}