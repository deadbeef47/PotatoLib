/*****************************************************************//**
 * \file   Type.h
 * \brief  汎用型宣言用ファイル
 *********************************************************************/
#pragma once

#include <cinttypes>
#include <vector>

namespace PotatoLib {


	//! 頂点インデックス配列型
	using VertexIndexArray = std::vector<uint32_t>;

	//! 頂点データ配列型
	using VertexDataArray = std::vector<float>;

	/**
	 * @enum EShaderType
	 * @brief シェーダータイプ
	 * @details Shaderコンパイル時の識別として使用する
	 */
	enum class EShaderType {
		//! 指定なし(例外処理用)
		eNone,
		//! 頂点シェーダー
		eVertex,
		//! フラグメントシェーダー
		eFragment,
	};

}
