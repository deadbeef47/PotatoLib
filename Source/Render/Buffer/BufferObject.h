#pragma once

#include "Framework\Type.h"

namespace PotatoLib {

	struct BufferObject {
		enum class EStatus {
			eSuccess,
			eCreateFail,
		};

		struct Attribute {
			uint32_t mLocation = 0u;
			int32_t mSize = 0;
			int32_t mStride = 0;
		};

		uint32_t mHandle = 0u;
		std::vector<Attribute> mAttributes;

		EStatus Create(const VertexDataArray& aDataArray);

		void PushAttribute(uint32_t aLocation, int32_t aSize, int32_t aStride);
		void SetupAttribute()const;

	};

}
