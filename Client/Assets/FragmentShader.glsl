#version 330 core

out vec4 o_Color;

in vec4 fs_Color;
in vec2 fs_TexCoords;

uniform sampler2D u_Texture;

void main() {

	o_Color = texture(u_Texture, fs_TexCoords) * fs_Color;

}