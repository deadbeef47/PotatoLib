#pragma once

#include "Framework\Type.h"

namespace  PotatoLib{

	struct BufferObject;

	struct VertexArrayObject {

		enum class EStatus {
			eSuccess,
			eCreateFail,
		};

		uint32_t mHandle = 0u;
		std::vector<int> mLocations;

		EStatus Create(const BufferObject& aBufferObject);
	};
}
