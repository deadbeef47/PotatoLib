/*****************************************************************//**
 * \file   TextWriter.h
 * \brief  テキスト出力
 *********************************************************************/
#pragma once

#include "Utility/ForwardDeclarationMacro.h"

STRING_FORWARD

namespace PotatoLib {
	/**
	 * @class TextReader.
	 * @brief テキスト入力
	 */
	class TextWriter {
	public:
		/**
		 * @brief ファイルセーブ.
		 *
		 * \param aPath セーブ用 パス/ファイル名
		 * \param aSaveText セーブするテキスト
		 * \return 成功/失敗
		 */
		static bool Save(const std::string& aPath, const std::string& aSaveText);

	private:
		/**
		 * @brief フォルダ作成.
		 * 
		 * \param aPath 指定のパス
		 * \return フォルダ作成に成功したか
		 */
		static bool CreateDirectory(const std::string& aPath);

	private:
	};
}
