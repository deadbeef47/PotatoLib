/*****************************************************************//**
 * \file   TextReader.h
 * \brief  テキスト入力
 *********************************************************************/
#pragma once

#include <string>

namespace PotatoLib {
	/**
	 * @class TextReader.
	 * @brief テキスト入力
	 */
	class TextReader {
	public:

		/**
		 * @brief ファイルロード.
		 * 
		 * \param aFileName ロード対象テキストファイル名
		 * \param aLoadText テキストファイルからロードしたテキスト
		 * \return 成功/失敗
		 */
		bool Load(const std::string& aFileName, std::string* aLoadText);

	private:
		/**
		 * @brief UTF-8 Bom付きの場合判定用の文字をスキップ.
		 * 
		 * \param aFile
		 */
		void SkipUTF8BOM(std::ifstream* aFile);

	private:
		std::string mFileName; //!< テキストファイル名
		std::string mFullText; //!< 全文文字列
	};
}

