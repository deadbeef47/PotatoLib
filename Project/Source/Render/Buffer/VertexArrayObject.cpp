#include "VertexArrayObject.h"

#include <GL\glew.h>
#include <functional>

#include "Utility\Assert.h"
#include "BufferObject.h"

namespace PotatoLib {

	VertexArrayObject::EStatus VertexArrayObject::Create(const BufferObject& aBufferObject) {

		Assert::Check(mHandle == 0, "���_�z��I�u�W�F�N�g�̃n���h�������ɍ쐬����Ă��܂�");

		glGenVertexArrays(1, &mHandle);

		// �����Ɏ��s�����n���h�������݂���
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



