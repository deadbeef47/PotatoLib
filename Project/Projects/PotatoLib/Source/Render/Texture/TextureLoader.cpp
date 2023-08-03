#include "TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

namespace PotatoLib {
	void TextureLoader::LoadTexture() {
		//stbi_loadf_from_file();
		int lX, lY, lComp;
		auto data = stbi_load("", &lX, &lY, &lComp, 0);
		if (!data)return;
		auto res = stbgl

		//stbi_image_free();
	}
}
