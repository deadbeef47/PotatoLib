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

			// スワップまでの待機時間を設定する
			glfwSwapInterval(1);

			// ウィンドウサイズ変わったコールバック
			glfwSetFramebufferSizeCallback(mHandle, [](auto aWindow, auto aWidth, auto aHeight) {});

			// Windowクラスをglfwと関連付ける
			glfwSetWindowUserPointer(mHandle, this);

			// カーソルの設定
			//glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	};
}
