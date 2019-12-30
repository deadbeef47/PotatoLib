#include "ElementArrayObject.h"

#include <GL\glew.h>

#include "Utility\Assert.h"

namespace PotatoLib {

	ElementArrayObject::EStatus ElementArrayObject::Create(const VertexIndexArray& aIndexArray) {

		Assert::Check(mHandle == 0, "頂点インデックスオブジェクトのハンドルが既に作成されています");

		glGenBuffers(1, &mHandle);

		if (mHandle == 0)
			return EStatus::eCreateFail;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mHandle);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, aIndexArray.size() * sizeof(unsigned int), aIndexArray.data(), GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		return EStatus::eSuccess;
	}

}