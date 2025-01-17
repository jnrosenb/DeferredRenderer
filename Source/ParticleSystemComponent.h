///HEADER STUFF

#pragma once

///INCLUDES
#include "../External/Includes/glm/glm.hpp"
#include "BaseComponent.h"
#include "Particle.h"
#include <vector>
#include <string>


//ERASE LATER------------------------------
#include "Shader.h"
#include "Model.h"
//ERASE LATER------------------------------
///class Shader;
///class Model;

class Operator;
class GameObject;

//TEMPORARY MEASURE - INCLUDES
#include "../External/Includes/Glad_/Glad/glad.h"
#include <gl/GL.h>



enum class EMISSION_SHAPE 
{
	SPHERE
};



class ParticleSystemComponent : public BaseComponent
{
public:
	friend class Factory;

	//PUBLIC INTERFACE
public:
	ParticleSystemComponent(GameObject *owner);
	virtual ~ParticleSystemComponent();

	virtual ParticleSystemComponent* clone() override
	{
		return new ParticleSystemComponent(m_owner);
	}
	virtual void Update(float dt) override;
	virtual void Draw() override;
	virtual void DeserializeInit() override;


	void EmitOnce(int num, float ttl, EMISSION_SHAPE shape);

	//TODO
	void ToggleContinuousEmition();
	void ContinuousEmition(int AvgNum, float ttl, EMISSION_SHAPE shape);

private:
	virtual void initModel();
	void SampleSpawnPosition(EMISSION_SHAPE shape, glm::vec3& pos);
	void RegisterParticleOperator(Operator *op);
	void RegisterParticleAdvector(Operator *op);

	void handleInput(float dt);


//ERASE LATER------------------------------
private:
	Model *debugRay;
	Shader	*debugShader;
	Model *targetMesh;
	void DebugDrawSetup()
	{
		this->debugShader = new Shader("Solid.vert", "Solid.frag");
		this->debugShader->BindUniformBlock("test_gUBlock", 1);
		this->debugRay = new Model("Vector.fbx");
		this->targetMesh = new Model(true, "sphere");
	}
//ERASE LATER------------------------------


public:
	//To compare when using templates
	static COMPONENT_TYPES const comp_class_type = PARTICLE_SYSTEM;

private:

	//Vector of particles
	std::vector<Particle*> m_particles;
	bool interactive;
	flockingParams m_flockingParams;

	//Operators (for non interactive particles)
	std::vector<Operator*> m_operators;
	std::vector<Operator*> m_advectors;
	int count;

	//Some particle params
	float ParticleMass;
	float ParticleAvoidanceDistance;
	bool avoidObstacle;

	//Vector of model matrices, for instancing
	std::vector<glm::mat4> modelMatrices;

	//TEMPORARY MEASURE
	GLuint instanceBuffer;

	//JUST WHILE NO SCRIPTING
	glm::vec3 target;

	//For now, pass this directly to particle. Later use descriptor
	bool use_loaded_mesh;
	Model *model = NULL;
	std::string modelPath;
	std::string primitive;
	std::string diffuseTexture;
	glm::vec4 diffuseColor;
	int xTiling, yTiling;
	glm::vec3 size;
	//bools (replace with feature mask on future)
	bool useDiffuseTexture;
};