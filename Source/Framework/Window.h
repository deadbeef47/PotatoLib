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

			glfwSwapInterval(1);

			glfwSetFramebufferSizeCallback(mHandle, [](auto aWindow, auto aWidth, auto aHeight) {});

			glfwSetWindowUserPointer(mHandle, nullptr);

			//glfwSetInputMode(mHandle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
	};
}
