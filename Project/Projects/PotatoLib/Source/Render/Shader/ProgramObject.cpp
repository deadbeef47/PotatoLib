#include "ProgramObject.h"

#include <GL\glew.h>

#include "Utility\Log.h"
#include "Utility\Assert.h"
#include "Render\Shader\ShaderObject.h"

namespace PotatoLib {

	ProgramObject::EStatus ProgramObject::Create() {

		Assert::Check(mHandle == 0, "�v���O�����I�u�W�F�N�g�̃n���h�������ɍ쐬����Ă��܂�");

		mHandle = glCreateProgram();

		if (mHandle == 0)
			return EStatus::eCreateFail;

		return EStatus::eSuccess;
	}

	ProgramObject::EStatus ProgramObject::Attach(const ShaderObject& aShaderObject) {

		Assert::Check(aShaderObject.mHandle != 0, "�V�F�[�_�[�I�u�W�F�N�g�̃n���h�����쐬����Ă��܂���");

		glAttachShader(mHandle, aShaderObject.mHandle);

		return EStatus::eSuccess;
	}

	ProgramObject::EStatus ProgramObject::Link() {

		glLinkProgram(mHandle);

		GLint lStatus = 0;
		glGetProgramiv(mHandle, GL_LINK_STATUS, &lStatus);
		if (GL_FALSE != lStatus) return EStatus::eSuccess;

		GLint lLogLength = 0;
		glGetProgramiv(mHandle, GL_INFO_LOG_LENGTH, &lLogLength);

		char* lLog = new char[lLogLength];
		if (0 < lLogLength) {
			glGetProgramInfoLog(mHandle, lLogLength, NULL, lLog);
		}

		Log::Show("Shader Link Log : ", lLog);
		delete[] lLog;

		return EStatus::eLinkFail;
	}
}
