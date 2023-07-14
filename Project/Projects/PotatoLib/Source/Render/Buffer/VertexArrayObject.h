/*****************************************************************//**
 * \file   VertexArrayObject.h
 * \brief  VAO ラッピングクラス
 *********************************************************************/
#pragma once

#include "Framework\Type.h"

namespace  PotatoLib {

	struct BufferObject;

	/**
	 * @struct VertexArrayObject.
	 * @brief VAO ラッピングクラス
	 */
	struct VertexArrayObject {

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

		//! VAO ハンドル
		uint32_t mHandle = 0u;
		//! 頂点属性配列
		std::vector<int> mLocations;

		/**
		 * @brief 頂点属性バッファオブジェクト作成.
		 * @details @ref BufferObject の内訳を決定しVAOを作成する
		 * \param aBufferObject 頂点バッファオブジェクト
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Create(const BufferObject& aBufferObject);
	};
}
