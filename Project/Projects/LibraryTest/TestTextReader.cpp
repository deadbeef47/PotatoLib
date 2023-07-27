#include "pch.h"
#include "IO/TextReader.h"

TEST(TextReaderTest, LoadExistingFile) {
    // テスト用のファイル名と内容
    const std::string testFileName = "test_file.txt";
    const std::string testFileContent =
        "Hello, Test Text!\n"
        "This is a multi-line text.\n"
        "It has three lines.";

    // テスト用のファイルを作成し、内容を書き込む
    std::ofstream outFile(testFileName);
    outFile << testFileContent;
    outFile.close();

    // TextReaderを使ってファイルを読み込む
    PotatoLib::TextReader textReader;
    std::string loadedText;
    bool loadResult = textReader.Load(testFileName, &loadedText);

    // ファイルの読み込みが成功したかを検証
    ASSERT_TRUE(loadResult);

    // 読み込まれたテキストの内容が正しいかを検証
    ASSERT_EQ(testFileContent, loadedText);

    loadResult = textReader.Load(testFileName, &loadedText);

    // ファイルの読み込みが成功したかを検証
    ASSERT_TRUE(loadResult);

    // 読み込まれたテキストの内容が正しいかを検証
    ASSERT_EQ(testFileContent, loadedText);

    // テスト用のファイルを削除
    remove(testFileName.c_str());
}

TEST(TextReaderTest, LoadNonExistentFile) {
    // 存在しないファイルを読み込む
    const std::string nonExistentFile = "non_existent_file.txt";

    // TextReaderを使ってファイルを読み込む
    PotatoLib::TextReader textReader;
    std::string loadedText;
    bool loadResult = textReader.Load(nonExistentFile, &loadedText);

    // ファイルの読み込みが失敗したかを検証
    ASSERT_FALSE(loadResult);

    // 読み込まれたテキストの内容が空であることを検証
    ASSERT_TRUE(loadedText.empty());
}


