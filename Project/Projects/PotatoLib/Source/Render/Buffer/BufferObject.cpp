#include "BufferObject.h"

#include <GL\glew.h>

#include <numeric>

#include "Utility\Assert.h"

namespace PotatoLib {

	BufferObject::EStatus BufferObject::Create(const VertexDataArray& aDataArray) {

		Assert::Check(mHandle == 0, "頂点バッファオブジェクトのハンドルが既に作成されています");

		glGenBuffers(1, &mHandle);
		glBindBuffer(GL_ARRAY_BUFFER, mHandle);

		glBufferData(GL_ARRAY_BUFFER, aDataArray.size() * sizeof(float), aDataArray.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

		return EStatus::eSuccess;
	}

	void BufferObject::PushAttribute(uint32_t aLocation, int32_t aSize) {
		mAttributes.emplace_back(Attribute{ aLocation, aSize });
	}

	void BufferObject::SetupAttribute()const {
		glBindBuffer(GL_ARRAY_BUFFER, mHandle);

		const auto lStride = std::accumulate(mAttributes.begin(), mAttributes.end(), 0, [](int32_t aVal, Attribute aAttrib) {
			return aVal + aAttrib.mSize * sizeof(float);
		});

		uint32_t lOffset = 0;
		for (int lIndex = 0; lIndex < mAttributes.size(); ++lIndex) {
			const Attribute& lAttr = mAttributes[lIndex];
			glEnableVertexAttribArray(lAttr.mLocation);

			glVertexAttribPointer(lAttr.mLocation, lAttr.mSize, GL_FLOAT, GL_FALSE, lStride, reinterpret_cast<void*>(lOffset));
			lOffset += lAttr.mSize * sizeof(float);

			glDisableVertexAttribArray(lAttr.mLocation);
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}