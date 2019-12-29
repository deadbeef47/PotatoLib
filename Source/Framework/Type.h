#pragma once

#include <cinttypes>

namespace PotatoLib {

	using ProgramHandle = uint32_t;
	using ShaderHandle = uint32_t;

	enum class EShaderType {
		eNone,
		eVertex,
		eFragment,
	};

}
