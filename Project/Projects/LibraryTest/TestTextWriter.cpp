#include "pch.h"
#include "IO/TextWriter.h"
#include <fstream>

TEST(TextWriterTest, SaveAndCreateDirectory) {
    // テスト用のディレクトリとファイル名
    const std::string testDir = "test_directory";
    const std::string testFile = testDir + "/test_file.txt";

    // テスト用の保存する複数行のテキスト
    const std::string testText =
        "Hello, Test Text!\n"
        "This is a multi-line text.\n"
        "It has three lines.\n";

    // TextWriterを使ってテキストを保存する
    bool saveResult = PotatoLib::TextWriter::Save(testFile, testText);

    // テキストの保存が成功したかを検証
    ASSERT_TRUE(saveResult);

    // ファイルが実際に存在するかを検証
    std::ifstream file(testFile.c_str());
    ASSERT_TRUE(file.good());

    // 保存されたテキストを読み込む（複数行）
    std::string loadedText;
    std::string line;
    while (std::getline(file, line)) {
        loadedText += line + "\n";
    }
    file.close();

    // テキストの内容が正しいかを検証
    ASSERT_EQ(testText, loadedText);

    // テストが終わったらファイルを削除
    remove(testFile.c_str());
    // テスト用のディレクトリを削除
    _rmdir(testDir.c_str());

}

