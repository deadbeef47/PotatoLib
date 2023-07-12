#pragma once

#include "Shader\ProgramObject.h"
#include "Shader\ShaderObject.h"
#include "Buffer\VertexArrayObject.h"
#include "Buffer\ElementArrayObject.h"
#include "Buffer\BufferObject.h"

#include <glm\glm.hpp>

namespace PotatoLib {
	class PolygonRender {
	public:
		void AddShader(EShaderType aShaderType, const char* aCode);
		void SetupProgram();
		void SetBuffer(const VertexIndexArray& aIndices, const BufferObject& aBufferObject);

		void Draw(const glm::mat4x4& aModelMatrix);

	private:
		ProgramObject mProgramObject;
		//ShaderObject mVertexShader, mFragmentShader;
		std::vector<ShaderObject> mShaders;
		VertexArrayObject mVertexArrayObject;
		ElementArrayObject mElementArrayObject;
	};
}
