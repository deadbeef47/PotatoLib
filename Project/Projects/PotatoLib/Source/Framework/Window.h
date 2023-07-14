/*****************************************************************//**
 * \file   Window.h
 * \brief  ウィンドウデータオブジェクト
 *********************************************************************/
#pragma once

#include <GLFW\glfw3.h>
#include <string>

namespace PotatoLib {

	/**
	 * @struct Window
	 * @brief ウィンドウデータオブジェクト
	 * @details ウィンドウ生成/パラメータ設定/初期化を実行
	 */
	struct Window {

		//! サイズ 横幅
		int mWidth = 640;
		//! サイズ 縦幅
		int mHeight = 480;
		//! 生成位置 X
		int mPosX = -1300;
		//! 生成位置 Y
		int mPosY = 500;
		//! タイトル
		std::string mTitle = "Title";
		//! ウィンドウハンドル
		GLFWwindow* mHandle = nullptr;

		Window() {

			mHandle = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
			glfwSetWindowPos(mHandle, mPosX, mPosY);

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
