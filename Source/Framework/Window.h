#pragma once

#include <GLFW\glfw3.h>
#include <string>

namespace PotatoLib {
	struct Window {

		int mWidth = 640, mHeight = 480;
		std::string mTitle = "Title";
		GLFWwindow* mHandle = nullptr;

		Window() {
		
			mHandle = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);

			glfwMakeContextCurrent(mHandle);

			// �X���b�v�܂ł̑ҋ@���Ԃ�ݒ肷��
			glfwSwapInterval(1);

			// �E�B���h�E�T�C�Y�ς�����R�[���o�b�N
			glfwSetFramebufferSizeCallback(mHandle, [](auto aWindow, auto aWidth, auto aHeight) {});

			// Window�N���X��glfw�Ɗ֘A�t����
			glfwSetWindowUserPointer(mHandle, this);

			// �J�[�\���̐ݒ�
			//glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	};
}
