// PotatoLib.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

// 使用ライブラリ
// https://github.com/glfw/glfw
#pragma comment(lib, "glfw3.lib")
// https://github.com/nigels-com/glew
//#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")

#pragma comment(lib, "opengl32.lib")

#include <iostream>
#include <GL\glew.h>

#include "Framework/GameApplication.h"
#include "Framework/Type.h"
#include "Render/PolygonRender.h"
#include <fstream>
#include <string>

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

#define AAA false

class Application : public PotatoLib::GameApplication
{
protected:
    void Initialize() override;
    void Draw() override;


    std::string GetShaderSource(const char* pFileName)
    {
        struct stat info;
        if (stat(pFileName, &info) != 0)
        {
            std::cout << "File not found" << std::endl;
            return "";
        }

        std::ifstream lInFile(pFileName, std::ios::in);
        if (!lInFile) return "";

        std::string lStr;
        std::istreambuf_iterator<char> lInput(lInFile);
        std::istreambuf_iterator<char> lLast;
        std::insert_iterator<std::string> lOut(lStr, lStr.end());
        std::copy(lInput, lLast, lOut);

        lInFile.close();

        return lStr;
    }

private:
    PotatoLib::PolygonRender render;
};

#if AAA
GLuint programId = 0;
GLuint vao = 0;
GLuint vertex_vbo = 0;
GLuint color_vbo = 0;


GLuint vi_vao = 0;
GLuint v_vbo = 0;
GLuint i_vbo = 0;
#endif

PotatoLib::BufferObject bo;

void Application::Initialize() {

#if AAA

    {
        GLuint vShaderId = glCreateShader(GL_VERTEX_SHADER);
        //const char* vs = GetShaderSource("GLSL/TestShader.vert").c_str();
        std::string vsStr = GetShaderSource("GLSL/TestShader.vert");
        const char* vs = vsStr.c_str();
        glShaderSource(vShaderId, 1, &vs, NULL);
        glCompileShader(vShaderId);


        GLuint fShaderId = glCreateShader(GL_FRAGMENT_SHADER);
        //const char* fs = GetShaderSource("GLSL/TestShader.frag").c_str();
        std::string fsStr = GetShaderSource("GLSL/TestShader.frag");
        const char* fs = fsStr.c_str();
        glShaderSource(fShaderId, 1, &fs, NULL);
        glCompileShader(fShaderId);

        programId = glCreateProgram();
        glAttachShader(programId, vShaderId);
        glAttachShader(programId, fShaderId);

        glLinkProgram(programId);
    }

    {
        glGenBuffers(1, &v_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, v_vbo);
        GLfloat datas[] = {
            -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
             0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,
             0.0f,  0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
        };
        //GLfloat datas[] = {
        //    -0.5f, -0.5f, 0.0f,
        //     0.5f, -0.5f, 0.0f,
        //     0.0f,  0.5f, 0.0f,
        //};
        glBufferData(GL_ARRAY_BUFFER, sizeof(datas), datas, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    {
        glGenBuffers(1, &i_vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_vbo);
        GLint indices[] = {
            0, 1, 2
        };
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    {
        glGenVertexArrays(1, &vi_vao);
        glBindVertexArray(vi_vao);
        glBindBuffer(GL_ARRAY_BUFFER, v_vbo);

        //glEnableVertexAttribArray(0);
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);

        //glEnableVertexAttribArray(1);
        //glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

        auto allSize = (3 * sizeof(GLfloat)) + (3 * sizeof(GLfloat));
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, allSize, (GLvoid*)0);

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, allSize, (GLvoid*)(3 * sizeof(GLfloat)));

        glBindVertexArray(0);
    }

#else
    render.AddShader(PotatoLib::EShaderType::eVertex,   GetShaderSource("GLSL/PolygonRender.vert").c_str());
    render.AddShader(PotatoLib::EShaderType::eFragment, GetShaderSource("GLSL/PolygonRender.frag").c_str());
    render.SetupProgram();

    PotatoLib::VertexIndexArray via{ 0, 1, 2,  0, 2, 3,  3, 2, 4 };
    PotatoLib::VertexDataArray vda{
        -0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, 1.0f, // idx 0
         0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.0f, 1.0f, // idx 1
         0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, 1.0f, // idx 2
        -0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f, 1.0f, // idx 3
         0.0f,  1.0f, 0.0f,  0.0f, 1.0f, 1.0f, 1.0f, // idx 4
    };
    bo.Create(vda);
    bo.PushAttribute(1, 3);
    bo.PushAttribute(2, 4);

    render.SetBuffer(via, bo);
#endif
}

float rotateY = 0.0f;

void Application::Draw() {

#if AAA
    glUseProgram(programId);

	glBindVertexArray(vi_vao);

    glBindBuffer(GL_ARRAY_BUFFER, v_vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
#else
    //render.Draw(glm::mat4x4(
    //    1.0f, 0.0f, 0.0f, 0.0f,
    //    0.0f, 1.0f, 0.0f, 0.0f,
    //    0.0f, 0.0f, 1.0f, 0.0f,
    //    0.0f, 0.0f, 0.0f, 1.0f));

    rotateY += 1.f;
    //rotateY = 0;
    auto rotateMat = glm::rotate(glm::mat4x4(1.0f), glm::radians(rotateY), glm::vec3(0.0f, 1.0f, 0.0f));
    //auto rotateMat = glm::rotate(glm::mat4x4(1.0f), 180.0f, glm::vec3(0.0f, 1.0f, 0.0f));
    auto translateMat = glm::translate(glm::mat4x4(1.0f), glm::vec3(1.0f, 0.0f, 3.0f));

    auto scaleMat = glm::scale(glm::mat4x4(1.0), glm::vec3(2.0f, 1.0f, 1.0f));
    //render.Draw(rotateMat * translateMat);
    render.Draw(translateMat * rotateMat * scaleMat);
#endif
}

int main(int argc, const char** argv)
{
    Application application;
    application.Run();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
