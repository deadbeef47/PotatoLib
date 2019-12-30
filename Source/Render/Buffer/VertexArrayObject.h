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

		EStatus Create(const BufferObject& aBufferObject);
	};
}
