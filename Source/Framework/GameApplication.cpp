#include "GameApplication.h"
#include "Utility\Log.h"

#include <GL\glew.h>
#include <GLFW\glfw3.h>
//#include <glm\glm.hpp>
#include "Framework\Window.h"

namespace PotatoLib {

	GameApplication::GameApplication() :
		mMajorVersion(4), mMinorVersion(3) {
	}

	void GameApplication::Run() {

		PotatoLog("glfw version : ", glfwGetVersionString());

		glfwSetErrorCallback([](int aError, const char* aDescription) {
			PotatoLog("Error Number: ", aError);
			PotatoLog("Description: ", aDescription);
		});

		if (glfwInit() == GL_FALSE) {
			PotatoLog("glfwInit error");
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, mMajorVersion);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, mMinorVersion);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		atexit([]() { glfwTerminate(); });

		Window lWindow;

		glewExperimental = GL_TRUE;
		GLenum lError = glewInit();
		if (GLEW_OK != lError) {
			PotatoLog("glewInit error : ", glewGetErrorString(lError));
			return;
		}

		Initialize();

		while (!(glfwWindowShouldClose(lWindow.mHandle) | glfwGetKey(lWindow.mHandle, GLFW_KEY_ESCAPE))) {

			Update();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glClearColor(0.0, 0.0, 0.0, 1.0);

			Draw();

			glfwSwapBuffers(lWindow.mHandle);
			//glfwWaitEvents();
			glfwPollEvents();
		}

		Finish();

	}
}
