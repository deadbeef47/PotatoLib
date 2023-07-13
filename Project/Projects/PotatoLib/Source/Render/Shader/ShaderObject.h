/*****************************************************************//**
 * \file   ShaderObject.h
 * \brief  シェーダーオブジェクトクラス
 *********************************************************************/
#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	/**
	 * @struct ShaderObject.
	 * @brief シェーダーオブジェクトクラス
	 */
	struct ShaderObject {
		/**
		 * @enum EStatus.
		 * @brief エラーハンドリング用ステータス
		 */
		enum class EStatus {
			//! 成功
			eSuccess,
			//! オブジェクト作成失敗
			eCreateFail,
			//! コンパイル失敗
			eCompileFail,
		};

		//! シェーダーオブジェクトハンドル
		uint32_t mHandle = 0u;
		//! 該当シェーダーのソースコード
		const char* mSourceCode = "";
		//! シェーダータイプ
		EShaderType mShaderType = EShaderType::eNone;

		/**
		 * @brief シェーダーオブジェクトセットアップ.
		 * @details シェーダーオブジェクト作成 → コンパイルを行う
		 * \param aShaderType シェーダータイプ
		 * \param aCode シェーダーソース
		 * \return 
		 */
		EStatus Setup(EShaderType aShaderType, const char* aCode);

		/**
		 * @brief シェーダーオブジェクト作成
		 * \param aShaderType シェーダータイプ
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Create(EShaderType aShaderType);

		/**
		 * @brief シェーダーコンパイル.
		 * 
		 * \param aCode シェーダーソース
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Compile(const char* aCode);
	};

}
