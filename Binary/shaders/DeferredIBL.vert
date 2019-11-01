//////////////////////////////////////////
// HEADER								//
//										//
// Name: Jose Rosenbluth Chiu			//
//                  					//
//////////////////////////////////////////

#version 330 core
     
layout(location = 0) in vec4 position;
layout(location = 2) in vec2 texcoords;


layout(std140) uniform test_gUBlock
{
	mat4 ProjView;							// 0   - 64
	mat4 LightProjView;						// 64   -128
	vec4 eye;								// 128  -144
};

out VS_OUT
{
	vec2 uv;
};

void main()
{
	gl_Position = position;
	uv = texcoords;
};