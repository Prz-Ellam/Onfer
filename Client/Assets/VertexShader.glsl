#version 330 core

layout (location = 0) in vec3 a_Pos;
layout (location = 1) in vec4 a_Color;
layout (location = 2) in vec2 a_TexCoords;

out vec4 fs_Color;
out vec2 fs_TexCoords;

uniform mat4 u_Projection;
uniform mat4 u_View;

void main() {

	gl_Position = u_Projection * u_View * vec4(a_Pos, 1.0f);
	fs_Color = a_Color;
	fs_TexCoords = a_TexCoords;

}