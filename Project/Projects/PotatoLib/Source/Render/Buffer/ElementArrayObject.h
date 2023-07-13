/*****************************************************************//**
 * \file   ElementArrayObject.h
 * \brief  頂点インデックスオブジェクト
 *********************************************************************/
#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	/**
	 * @struct ElementArrayObject.
	 * @brief 頂点インデックスオブジェクト
	 */
	struct ElementArrayObject {

		/**
		 * @enum EStatus.
		 * @brief エラーハンドリング用ステータス
		 */
		enum class EStatus {
			//! 成功
			eSuccess,
			//! オブジェクト作成失敗
			eCreateFail,
		};

		//! インデックスオブジェクトハンドル
		uint32_t mHandle = 0u;

		/**
		 * @brief 頂点インデックスオブジェクト作成.
		 * 
		 * \param aIndexArray 頂点配列 @ref VertexIndexArray
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Create(const VertexIndexArray& aIndexArray);

	};

}
