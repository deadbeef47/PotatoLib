#include "ShaderObject.h"

#include <GL\glew.h>
#include "Utility\Log.h"
#include "Utility\Assert.h"

namespace PotatoLib {

	ShaderObject::EStatus ShaderObject::Setup(EShaderType aShaderType, const char* aCode) {

		const auto lCreateRes = Create(aShaderType);
		if (lCreateRes != EStatus::eSuccess)
			return lCreateRes;

		const auto lCompileRes = Compile(aCode);
		if (lCompileRes != EStatus::eSuccess)
			return lCompileRes;
	}

	ShaderObject::EStatus ShaderObject::Create(EShaderType aShaderType) {
		Assert::Check(mHandle == 0, "シェーダーオブジェクトのハンドルが既に作成されています");

		GLenum lShaderType = 0;
		switch (aShaderType) {
		case PotatoLib::EShaderType::eVertex:
			lShaderType = GL_VERTEX_SHADER;
			break;
		case PotatoLib::EShaderType::eFragment:
			lShaderType = GL_FRAGMENT_SHADER;
			break;
		default:
			Assert::Check("想定外のEShaderTypeが指定されました");
			break;
		}

		mHandle = glCreateShader(lShaderType);

		if (mHandle == 0)
			return EStatus::eCreateFail;

		return EStatus::eSuccess;
	}

	ShaderObject::EStatus ShaderObject::Compile(const char* aCode) {

		mSourceCode = aCode;

		glShaderSource(mHandle, 1, &mSourceCode, NULL);

		glCompileShader(mHandle);

		GLint lStatus = 0;
		glGetShaderiv(mHandle, GL_COMPILE_STATUS, &lStatus);
		if (GL_FALSE != lStatus) return EStatus::eSuccess;

		GLint lLogLength = 0;
		glGetShaderiv(mHandle, GL_INFO_LOG_LENGTH, &lLogLength);

		if (0 <= lLogLength) return EStatus::eSuccess;

		std::string lLog;
		glGetShaderInfoLog(mHandle, lLogLength, NULL, &lLog[0]);

		Log::Show("Shader Compile Log : ", lLog);
		return EStatus::eCompileFail;
	}

}