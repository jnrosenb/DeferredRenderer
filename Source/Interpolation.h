#pragma once

#include <iostream>
#include <string>
#include "../External/Includes/glm/glm.hpp"
#include "../External/Includes/glm/gtc/matrix_transform.hpp"

class Quaternion;


namespace AuxMath 
{
	glm::vec3 Lerp(glm::vec3 const& origin, glm::vec3 const& destination, float alpha);

	Quaternion Slerp(Quaternion const& origin, Quaternion const& destination, float alpha);

	glm::mat4 GenVQSMatrix(glm::vec3 const& v, Quaternion const& q, glm::vec3 const& s);
}