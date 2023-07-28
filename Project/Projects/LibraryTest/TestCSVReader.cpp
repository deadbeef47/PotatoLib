#include "pch.h"
#include "IO/CSVReader.h"

TEST(CSVReaderTest, GetStringValidIndices) {
    // テスト用のファイル名と内容
    const std::string testFileName = "test_file.csv";
    const std::string testFileContent =
        "apple,orange,banana\n"
        "grape,kiwi,pear\n";

    // テスト用のファイルを作成し、内容を書き込む
    std::ofstream outFile(testFileName);
    outFile << testFileContent;
    outFile.close();

    // CSVReaderを使ってファイルを読み込む
    PotatoLib::CSVReader csvReader;
    csvReader.Load(testFileName);

    // 有効な位置のデータにアクセスするテスト
    ASSERT_EQ(csvReader.GetString(0, 0), "apple");
    ASSERT_EQ(csvReader.GetString(0, 1), "orange");
    ASSERT_EQ(csvReader.GetString(0, 2), "banana");
    ASSERT_EQ(csvReader.GetString(1, 0), "grape");
    ASSERT_EQ(csvReader.GetString(1, 1), "kiwi");
    ASSERT_EQ(csvReader.GetString(1, 2), "pear");

    // テスト用のファイルを削除
    remove(testFileName.c_str());
}

TEST(CSVReaderTest, GetFloatValidIndices) {
    // テスト用のファイル名と内容
    const std::string testFileName = "test_file.csv";
    const std::string testFileContent =
        "1.5,2.25,3.75\n"
        "4.0,5.5,6.125\n";

    // テスト用のファイルを作成し、内容を書き込む
    std::ofstream outFile(testFileName);
    outFile << testFileContent;
    outFile.close();

    // CSVReaderを使ってファイルを読み込む
    PotatoLib::CSVReader csvReader;
    csvReader.Load(testFileName);

    // 有効な位置のデータにアクセスするテスト
    ASSERT_FLOAT_EQ(csvReader.GetFloat(0, 0), 1.5f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(0, 1), 2.25f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(0, 2), 3.75f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(1, 0), 4.0f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(1, 1), 5.5f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(1, 2), 6.125f);

    // テスト用のファイルを削除
    remove(testFileName.c_str());
}

TEST(CSVReaderTest, GetStringInvalidIndices) {
    // テスト用のファイル名と内容
    const std::string testFileName = "test_file.csv";
    const std::string testFileContent =
        "apple,orange,banana\n"
        "grape,kiwi,pear\n";

    // テスト用のファイルを作成し、内容を書き込む
    std::ofstream outFile(testFileName);
    outFile << testFileContent;
    outFile.close();

    // CSVReaderを使ってファイルを読み込む
    PotatoLib::CSVReader csvReader;
    csvReader.Load(testFileName);

    // 存在しない位置のデータにアクセスするテスト
    ASSERT_EQ(csvReader.GetString(2, 0), "");
    ASSERT_EQ(csvReader.GetString(0, 3), "");
    ASSERT_EQ(csvReader.GetString(2, 2), "");

    // テスト用のファイルを削除
    remove(testFileName.c_str());
}

TEST(CSVReaderTest, GetFloatInvalidIndices) {
    // テスト用のファイル名と内容
    const std::string testFileName = "test_file.csv";
    const std::string testFileContent =
        "1.5,2.25,3.75\n"
        "4.0,5.5,6.125\n";

    // テスト用のファイルを作成し、内容を書き込む
    std::ofstream outFile(testFileName);
    outFile << testFileContent;
    outFile.close();

    // CSVReaderを使ってファイルを読み込む
    PotatoLib::CSVReader csvReader;
    csvReader.Load(testFileName);

    // 存在しない位置のデータにアクセスするテスト
    ASSERT_FLOAT_EQ(csvReader.GetFloat(2, 0), 0.0f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(0, 3), 0.0f);
    ASSERT_FLOAT_EQ(csvReader.GetFloat(2, 2), 0.0f);

    // テスト用のファイルを削除
    remove(testFileName.c_str());
}
