#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 45.0f * DEGTORAD
#define BRAKE_POWER 50.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	void CameraFollow(float dt);

	bool Start();
	update_status Update(float dt);
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2) override;
	bool CleanUp();

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	//btVector3 g;

	//float val = -10.0f;

	btTransform carPos;
	vec3 initialCarPos = { 0,0,0 };
	vec3 carDir = { 0,0,0 };
	vec3 cameraPos = { 0,0,0 };
	vec3 oldCameraPos = { 0,0,0 };

};