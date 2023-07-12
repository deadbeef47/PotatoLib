#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	struct ShaderObject {
		enum class EStatus {
			eSuccess,
			eCreateFail,
			eCompileFail,
		};

		uint32_t mHandle = 0u;
		const char* mSourceCode = "";
		EShaderType mShaderType = EShaderType::eNone;

		EStatus Setup(EShaderType aShaderType, const char* aCode);
		EStatus Create(EShaderType aShaderType);
		EStatus Compile(const char* aCode);
	};

}
