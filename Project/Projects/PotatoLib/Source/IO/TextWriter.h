/*****************************************************************//**
 * \file   TextWriter.h
 * \brief  テキスト出力
 *********************************************************************/
#pragma once

#include "Utility/ForwardDeclarationMacro.h"

STRING_FORWARD

namespace PotatoLib {

	// TODO: 各モードへの対応を考える
	/**
	 * @enum 書き込みモード.
	 */
	enum class SaveMode {
		eNone,		//!< 指定無し エラー検出用
		eCreate,	//!< 新規作成 既に存在する場合は
		eOverride,	//!< 上書き
		eAppend,	//!< 加筆
	};

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
