#pragma once

#include <Framework/GameApplication.h>
#include <Framework/Type.h>
#include <Render/PolygonRender.h>


#include <string>
#include <iostream>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

class Application : public PotatoLib::GameApplication
{
protected:
	void Initialize() override {

		// シェーダーロード / コンパイル / リンク
		render.AddShader(PotatoLib::EShaderType::eVertex, GetShaderSource("GLSL/PolygonRender.vert").c_str());
		render.AddShader(PotatoLib::EShaderType::eFragment, GetShaderSource("GLSL/PolygonRender.frag").c_str());
		render.SetupProgram();

		// 頂点データセットアップ
		PotatoLib::VertexIndexArray via{ 0, 1, 2 };
		PotatoLib::VertexDataArray vda{
			-0.5f, -((float)glm::sqrt(3) / 4.0f), 0.0f,  1.0f, 0.0f, 0.0f, 1.0f, // idx 0
			 0.5f, -((float)glm::sqrt(3) / 4.0f), 0.0f,  0.0f, 1.0f, 0.0f, 1.0f, // idx 1
			 0.0f,  ((float)glm::sqrt(3) / 4.0f), 0.0f,  0.0f, 0.0f, 1.0f, 1.0f, // idx 2
		};
		;

		PotatoLib::BufferObject bo;
		bo.Create(vda);
		bo.PushAttribute(1, 3);
		bo.PushAttribute(2, 4);

		render.SetBuffer(via, bo);
	}

	void Update() override {
		mRotateY += 1.f;
	}

	void Draw() override {
		auto rotateYRad = glm::radians(mRotateY);
		auto translateMat = glm::translate(glm::mat4x4(1.0f), glm::vec3(glm::sin(rotateYRad), 0.0f, 0.0f));
		auto rotateMat = glm::rotate(glm::mat4x4(1.0f), rotateYRad * 2.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		auto scaleMat = glm::scale(glm::mat4x4(1.0), glm::vec3(1.0f, 1.0f, 1.0f) * 3.0f);

		render.Draw(translateMat * rotateMat * scaleMat);
	}


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
	float mRotateY = 0.0f;
};
