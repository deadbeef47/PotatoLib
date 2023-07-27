#include "pch.h"
#include <Utility/PathUtility.h>


// PotatoLibのPathUtilityクラスのテストフィクスチャクラス
class PathUtilityTest : public ::testing::Test {
protected:
    void SetUp() override {
        // テストごとにセットアップする場合はここに記述
    }

    void TearDown() override {
        // テストごとに後処理する場合はここに記述
    }
};


// テストケース
TEST_F(PathUtilityTest, GetDirectoryTest) {
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("C:\\path\\to\\file.txt"), "C:\\path\\to");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("C:\\path/to\\file.txt"), "C:\\path/to");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("file.txt"), "");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("C:/path/to/file.txt"), "C:/path/to");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("/path/to/file.txt"), "/path/to");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("C:\\path\\to\\"), "C:\\path\\to");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory("C:\\path\\to"), "C:\\path");
    EXPECT_EQ(PotatoLib::PathUtility::GetDirectory(""), ""); // 空文字列
}

TEST_F(PathUtilityTest, GetFileNameTest) {
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:\\path\\to\\file.txt"), "file.txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:\\path/to\\file.txt"), "file.txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("file.txt"), "file.txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:/path/to/file.txt"), "file.txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("/path/to/file.txt"), "file.txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:\\path\\to\\"), "");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:\\path\\to"), "to");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName(""), ""); // 空文字列
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("FileName.txt.txt"), "FileName.txt.txt"); // 拡張子が複数ある場合
    EXPECT_EQ(PotatoLib::PathUtility::GetFileName("C:\\path/to\\FileName.txt.txt"), "FileName.txt.txt"); // 拡張子が複数ある場合
}

TEST_F(PathUtilityTest, GetFileExtensionTest) {
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:\\path\\to\\file.txt"), "txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:\\path/to\\file.txt"), "txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("file.txt"), "txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:/path/to/file.txt"), "txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("/path/to/file.txt"), "txt");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:\\path\\to\\"), "");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:\\path\\to"), "");
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension(""), ""); // 空文字列
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("FileName.txt.txt"), "txt"); // 拡張子が複数ある場合
    EXPECT_EQ(PotatoLib::PathUtility::GetFileExtension("C:\\path/to\\FileName.txt.txt"), "txt"); // 拡張子が複数ある場合
}


TEST_F(PathUtilityTest, GetElementArrayTest) {
    // テストケース1: スラッシュとバックスラッシュが混同したパス
    std::string path1 = "path/to\\some/file.txt";
    std::vector<std::string> expected1 = { "path", "to", "some", "file.txt" };
    EXPECT_EQ(PotatoLib::PathUtility::GetElementArray(path1), expected1);

    // テストケース2: さらに混在したパス
    std::string path2 = "a/b\\c\\d/e\\f";
    std::vector<std::string> expected2 = { "a", "b", "c", "d", "e", "f" };
    EXPECT_EQ(PotatoLib::PathUtility::GetElementArray(path2), expected2);

    // テストケース3: パスにディレクトリ区切り文字が含まれない場合
    std::string path3 = "file.txt";
    std::vector<std::string> expected3 = { "file.txt" };
    EXPECT_EQ(PotatoLib::PathUtility::GetElementArray(path3), expected3);

    // テストケース4: パスが空文字列の場合
    std::string path4 = "";
    std::vector<std::string> expected4 = {};
    EXPECT_EQ(PotatoLib::PathUtility::GetElementArray(path4), expected4);

}
