/*****************************************************************//**
 * \file   PolygonRender.h
 * \brief  ポリゴン描画
 *********************************************************************/
#pragma once

#include "Shader\ProgramObject.h"
#include "Shader\ShaderObject.h"
#include "Buffer\VertexArrayObject.h"
#include "Buffer\ElementArrayObject.h"
#include "Buffer\BufferObject.h"

#include <glm\glm.hpp>

namespace PotatoLib {
	/**
	 * @class PolygonRender.
	 * @brief ポリゴン描画
	 */
	class PolygonRender {
	public:
		/**
		 * @brief 各シェーダーステージ追加.
		 * \param aShaderType シェーダータイプ
		 * \param aCode シェーダーソース
		 */
		void AddShader(EShaderType aShaderType, const char* aCode);

		/**
		 * @brief プログラムセットアップ.
		 * @details @ref AddShader で追加したシェーダーステージの結合・セットアップ
		 * @sa ProgramObject
		 */
		void SetupProgram();

		/**
		 * @brief 頂点情報セット.
		 * \param aIndices 頂点インデックス
		 * \param aBufferObject 頂点データ
		 */
		void SetBuffer(const VertexIndexArray& aIndices, const BufferObject& aBufferObject);

		/**
		 * @brief 描画実行.
		 * \param aModelMatrix モデル行列(Translate Rotate Scale)
		 */
		void Draw(const glm::mat4x4& aModelMatrix);

	private:
		//! プログラムオブジェクトインスタンス
		ProgramObject mProgramObject;
		//! シェーダーステージ配列
		std::vector<ShaderObject> mShaders;
		//! 頂点でーたオブジェクト
		VertexArrayObject mVertexArrayObject;
		//! インデックス配列オブジェクト
		ElementArrayObject mElementArrayObject;
	};
}
