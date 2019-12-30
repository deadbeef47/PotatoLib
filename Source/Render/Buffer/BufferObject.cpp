#include "BufferObject.h"

#include <GL\glew.h>

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

	void BufferObject::PushAttribute(uint32_t aLocation, int32_t aSize, int32_t aStride) {
		mAttributes.emplace_back(Attribute{ aLocation, aSize, aStride });
	}

	void BufferObject::SetupAttribute()const {
		glBindBuffer(GL_ARRAY_BUFFER, mHandle);

		for (const Attribute& lAttr : mAttributes) {
			glEnableVertexAttribArray(lAttr.mLocation);

			glVertexAttribPointer(lAttr.mLocation, lAttr.mSize, GL_FLOAT, GL_FALSE, lAttr.mStride, 0);

			glDisableVertexAttribArray(lAttr.mLocation);
		}

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}