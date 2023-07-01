#pragma once

#include <cinttypes>
#include <vector>

namespace PotatoLib {

	// Shader

	// Buffer
	using VertexIndexArray = std::vector<uint32_t>;
	using VertexDataArray = std::vector<float>;

	enum class EShaderType {
		eNone,
		eVertex,
		eFragment,
	};

}
