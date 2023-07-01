#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	struct ShaderObject;

	struct ProgramObject {
		enum class EStatus {
			eSuccess,
			eCreateFail,
			eLinkFail,
		};

		uint32_t mHandle = 0u;

		EStatus Create();
		EStatus Attach(const ShaderObject& aShaderObject);
		EStatus Link();
	};

}
