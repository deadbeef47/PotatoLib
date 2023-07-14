#version 430

layout (location = 1) in vec3 VertexPosition;
layout (location = 2) in vec4 VertexColor;

out vec4 Color;

uniform mat4 aModel;
uniform mat4 aView;
uniform mat4 aProjection;

void main()
{ 
	Color = VertexColor;
	gl_Position = aProjection * aView * aModel * vec4(VertexPosition, 1.0);
}
