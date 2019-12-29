#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	struct ShaderObject {
		enum class EStatus {
			eSuccess,
			eCreateFail,
			eCompileFail,
		};

		ShaderHandle mHandle = 0u;
		const char* mSourceCode = "";
		EShaderType mShaderType = EShaderType::eNone;

		explicit ShaderObject(const char* aCode);
		EStatus Create(EShaderType aShaderType);
		EStatus Compile();
	};

}
