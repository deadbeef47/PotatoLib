﻿#version 430

in vec4 Color;

layout (location = 0) out vec4 FragColor;

void main()
{
	FragColor = vec4(Color.xyz, 1.0);
}
