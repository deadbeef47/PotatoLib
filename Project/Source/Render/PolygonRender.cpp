#include "PolygonRender.h"
#include <GL\glew.h>
#include <glm\gtc\type_ptr.hpp>

namespace PotatoLib {

	void PolygonRender::AddShader(EShaderType aShaderType, const char* aCode) {
		ShaderObject lShaderObject;
		lShaderObject.Setup(aShaderType, aCode);
		mShaders.emplace_back(lShaderObject);
	}

	void PolygonRender::SetupProgram() {
		mProgramObject.Create();

		for (const ShaderObject& lShader : mShaders) {
			mProgramObject.Attach(lShader);
		}
		mProgramObject.Link();
	}

	void PolygonRender::SetBuffer(const VertexIndexArray& aIndices, const BufferObject& aBufferObject) {
		mElementArrayObject.Create(aIndices);
		mVertexArrayObject.Create(aBufferObject);
	}

	void PolygonRender::Draw(const glm::mat4x4& aModelMatrix) {
		glUseProgram(mProgramObject.mHandle);

		glBindVertexArray(mVertexArrayObject.mHandle);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mElementArrayObject.mHandle);

		for (auto location : mVertexArrayObject.mLocations)
		{
			glEnableVertexAttribArray(location);
		}

		const auto lModelMatLoc = glGetUniformLocation(mProgramObject.mHandle, "aModel");
		glUniformMatrix4fv(lModelMatLoc, 1, GL_FALSE, glm::value_ptr(aModelMatrix));

		const auto lViewMatLoc = glGetUniformLocation(mProgramObject.mHandle, "aView");
		glUniformMatrix4fv(lViewMatLoc, 1, GL_FALSE, glm::value_ptr(glm::lookAt(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))));

		const auto lProjMatLoc = glGetUniformLocation(mProgramObject.mHandle, "aProjection");
		glUniformMatrix4fv(lProjMatLoc, 1, GL_FALSE, glm::value_ptr(glm::perspective(glm::radians(65.0f), 4.0f / 3.0f, 0.1f, 1000.0f)));

		//glDrawArrays(GL_TRIANGLES, 0, 9);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, reinterpret_cast<const GLvoid*>(0));

		for (auto location : mVertexArrayObject.mLocations)
		{
			glDisableVertexAttribArray(location);
		}

		glBindVertexArray(0);

		glUseProgram(0);
	}

}
