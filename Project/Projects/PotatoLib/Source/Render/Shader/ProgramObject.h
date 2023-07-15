/*****************************************************************//**
 * \file   ProgramObject.h
 * \brief  シェーダーステージ結合クラス
 *********************************************************************/
#pragma once

#include ".\Type\Type.h"

namespace PotatoLib {

	struct ShaderObject;

	/**
	 * @struct ProgramObject.
	 * @brief シェーダーステージ結合クラス
	 */
	struct ProgramObject {
		/**
		 * @enum EStatus.
		 * @brief エラーハンドリング用ステータス
		 */
		enum class EStatus {
			//! 成功
			eSuccess,
			//! オブジェクト作成失敗
			eCreateFail,
			//! リンク失敗
			eLinkFail,
		};

		//! プログラムハンドル
		uint32_t mHandle = 0u;

		/**
		 * @brief プログラムオブジェクト作成
		 *
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Create();
		/**
		 * @brief アタッチするシェーダーオブジェクト指定.
		 *
		 * \param aShaderObject 対象シェーダーオブジェクト
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Attach(const ShaderObject& aShaderObject);
		/**
		 * @brief 各シェーダーステージをリンク.
		 *
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Link();
	};

}
