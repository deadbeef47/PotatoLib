#include "ShaderObject.h"

#include <GL\glew.h>
#include "Utility\Log.h"
#include "Utility\Assert.h"

namespace PotatoLib {

	ShaderObject::ShaderObject(const char* aCode) :
		mSourceCode(aCode), mShaderType(EShaderType::eNone) {
	}

	ShaderObject::EStatus ShaderObject::Create(EShaderType aShaderType) {
		Assert::Check(mHandle == 0, "�V�F�[�_�[�I�u�W�F�N�g�̃n���h�������ɍ쐬����Ă��܂�");

		GLenum lShaderType = 0;
		switch (aShaderType) {
		case PotatoLib::EShaderType::eVertex:
			lShaderType = GL_VERTEX_SHADER;
			break;
		case PotatoLib::EShaderType::eFragment:
			lShaderType = GL_FRAGMENT_SHADER;
			break;
		default:
			Assert::Check("�z��O��EShaderType���w�肳��܂���");
			break;
		}

		mHandle = glCreateShader(lShaderType);

		if (mHandle == 0)
			return EStatus::eCreateFail;

		return EStatus::eSuccess;
	}

	ShaderObject::EStatus ShaderObject::Compile() {

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