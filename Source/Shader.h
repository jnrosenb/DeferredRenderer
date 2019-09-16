///HEADER STUFF

#pragma once

///INCLUDES
///#include "../External/Includes/GL/glew.h"
#include "../External/Includes/Glad_/Glad/glad.h"
#include <gl/GL.h>
#include "../External/Includes/glm/glm.hpp"
#include <unordered_map>
#include <string>

static std::string const ShaderDir = "C:\\Users\\Jose\\Desktop\\OpenGl_Framework\\Binary\\shaders\\";


class Shader 
{
//PUBLIC INTERFACE
public:
	Shader(char const *vertexPath, char const *fragmentPath);
	virtual ~Shader();

	GLint GetId() const;
	bool IsValid() const;
	void UseShader();
	void UnbindShader();

	// Uniform data passing functions (CHANGE LATER TO CONST FUNCTIONS)
	void setFloat(const std::string &name, float value);
	void setVec3f(const std::string &name, float x, float y, float z);
	void setVec4f(const std::string &name, float x, float y, float z, float w);
	void setMat4f(const std::string &name, glm::mat4& matrix);

	//Texture uniform passing
	void setTexture(std::string const& name, GLuint texture, int unit);

	//Uniform block binding
	void BindUniformBlock(std::string const& name, int bind_index);


//VARIABLES
private:
	GLint programId;

	std::unordered_map<std::string, GLuint> UniformLocationMap;

//PRIVATE METHODS
private:
	Shader(Shader& rhs);
	GLuint GetCachedUniformLocation(std::string const& name);

};