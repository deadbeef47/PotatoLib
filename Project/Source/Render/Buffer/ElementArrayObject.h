#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	struct ElementArrayObject {
		enum class EStatus {
			eSuccess,
			eCreateFail,
		};

		uint32_t mHandle = 0u;

		EStatus Create(const VertexIndexArray& aIndexArray);

	};

}
