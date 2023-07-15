/*****************************************************************//**
 * \file   BufferObject.h
 * \brief  VBO ラッピングクラス
 *********************************************************************/
#pragma once

#include "../../Type/Type.h"

namespace PotatoLib {

	/**
	 * @struct BufferObject
	 * @brief VBO ラッピングクラス
	 */
	struct BufferObject {

		/**
		 * @enum EStatus
		 * @brief エラーハンドリング用ステータス
		 */
		enum class EStatus {
			//! 成功
			eSuccess,
			//! オブジェクト作成失敗
			eCreateFail,
		};

		/**
		 * @struct Attribute.
		 * @brief 頂点属性データ
		 */
		struct Attribute {
			//! 属性ID
			uint32_t mLocation = 0u;
			//! 要素数
			int32_t mSize = 0;
		};

		//! VBO ハンドル
		uint32_t mHandle = 0u;
		//! 頂点属性データ配列
		std::vector<Attribute> mAttributes;

		/**
		 * 頂点バッファオブジェクト作成.
		 *
		 * \param aDataArray 頂点データ配列 @ref VertexDataArray
		 * \return エラーハンドリング用リザルト
		 */
		EStatus Create(const VertexDataArray& aDataArray);

		/**
		 * @brief 頂点属性を追加.
		 *
		 * \param aLocation 属性ID
		 * \param aSize 要素数
		 */
		void PushAttribute(uint32_t aLocation, int32_t aSize);

		/**
		 * @brief 頂点情報内訳FIX.
		 * @details @ref PushAttribute 実行後に処理する
		 */
		void SetupAttribute()const;

	};

}
