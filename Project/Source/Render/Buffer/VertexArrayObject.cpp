#include "VertexArrayObject.h"

#include <GL\glew.h>
#include <functional>

#include "Utility\Assert.h"
#include "BufferObject.h"

namespace PotatoLib {

	VertexArrayObject::EStatus VertexArrayObject::Create(const BufferObject& aBufferObject) {

		Assert::Check(mHandle == 0, "頂点配列オブジェクトのハンドルが既に作成されています");

		glGenVertexArrays(1, &mHandle);

		// 生成に失敗したハンドルが存在する
		if (mHandle == 0)
			return EStatus::eCreateFail;

		for (auto attribute : aBufferObject.mAttributes) {
			mLocations.emplace_back(attribute.mLocation);
		}

		glBindVertexArray(mHandle);

		aBufferObject.SetupAttribute();

		glBindVertexArray(0);

		return EStatus::eSuccess;
	}
}



