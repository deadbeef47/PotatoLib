/*****************************************************************//**
 * \file   PathUtility.h
 * \brief  パスパーサー
 *********************************************************************/
#pragma once

#include <string>
#include <vector>

namespace PotatoLib {
	/**
	 * @class PathUtility
	 * @brief パスパーサー.
	 */
	class PathUtility {
	public:
		/**
		 * @brief パスからディレクトリ取得.
		 * 
		 * \param aPath パス
		 * \return ディレクトリ名
		 */
		static std::string GetDirectory(const std::string& aPath);
		/**
		 * @brief パスからファイル名取得.
		 * 
		 * \param aPath パス
		 * \return ファイル名
		 */
		static std::string GetFileName(const std::string& aPath);
		/**
		 * @brief パスから拡張子取得.
		 * 
		 * \param aPath パス
		 * \return 拡張子
		 */
		static std::string GetFileExtension(const std::string& aPath);

		/**
		 * @brief フォルダ/ファイル単位で文字列を配列化する.
		 * 
		 * \param aPath パス
		 * \return フォルダ/ファイル配列
		 */
		static std::vector<std::string> GetElementArray(const std::string& aPath);
	private:
	};
}
