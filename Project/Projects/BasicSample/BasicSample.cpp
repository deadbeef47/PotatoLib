
// 使用ライブラリ
// https://github.com/glfw/glfw
#pragma comment(lib, "glfw3.lib")
// https://github.com/nigels-com/glew
//#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")

#pragma comment(lib, "opengl32.lib")

#include "Application.h"

int main(int argc, const char** argv)
{
	Application application;
	application.Run();
}

