#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->audio->PlayMusic("Audio/dubiduba.ogg");
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(App->player->initialCarPos);

	// Create sensor cube (will trigger with car)
	/*sensor_cube = App->physics->AddBody(Cube(5, 5, 5), 0.0);
	sensor_cube->SetAsSensor(true);
	sensor_cube->SetPos(0, 3, 0);*/

	/*sog.CreateRectangle({ 0,0,0 }, { 0,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5,42.5 }, { 45,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5*2,42.5*2 }, { 0,0,0 }, { 10,1,50 });*/

	//sog.CreateRectangle({ 46.42, 6.06, 16.11 }, { -0.04, -0.05, -0.12 }, { 76.63, 48.58, 56.44 });
	sog.CreateRectangle({ 46.42, 6.06, 16.11 }, { -0.04, -0.05, -0.12 }, { 0.93, 7.51, 0.31 });
	sog.CreateRectangle({ 59.17, -9.58, 66.34 }, { 3.14, -0.00, 0.00 }, { 18.14, 24.87, -0.67 });
	sog.CreateRectangle({ 2.45, -9.31, 26.67 }, { 0.00, 0.00, 0.00 }, { 18.14, 88.75, 0.67 });
	sog.CreateRectangle({ 5.07, 0.39, 20.81 }, { 0.00, -0.00, -1.57 }, { 13.27, 119.29, 0.48 });
	sog.CreateRectangle({ -34.57, -6.82, 57.66 }, { 0.10, 2.98, 0.04 }, { 18.14, 35.65, 0.67 });
	sog.CreateRectangle({ -51.43, -4.59, 37.61 }, { 0.05, -3.03, 1.46 }, { 12.47, 19.54, 0.67 });
	sog.CreateRectangle({ 112.53, 8.29, -30.07 }, { -0.01, -3.11, -0.02 }, { 18.14, 70.57, 0.67 });
	sog.CreateRectangle({ 78.07, 7.09, -91.62 }, { -0.03, -3.12, -0.02 }, { 18.14, 26.99, 0.67 });
	sog.CreateRectangle({ 39.90, 7.18, -116.23 }, { 0.00, -0.00, -1.60 }, { 11.71, 70.35, 0.67 });
	sog.CreateRectangle({ 2.58, 14.56, -93.53 }, { -0.29, 3.08, -0.02 }, { 17.69, 27.00, 0.67 });
	sog.CreateRectangle({ 2.85, 25.97, -62.21 }, { -0.39, 3.08, -0.03 }, { 17.70, 42.18, 0.67 });
	sog.CreateRectangle({ 95.16, 7.71, -71.77 }, { -3.12, -0.03, 1.55 }, { 11.27, 19.19, 0.67 });
	sog.CreateRectangle({ 82.79, 7.31, 6.87 }, { 0.04, -0.00, 1.52 }, { 11.98, 71.38, 0.67 });
	sog.CreateRectangle({ 75.04, -1.49, -7.92 }, { -3.07, 0.08, 0.01 }, { 16.30, 39.00, 0.67 });
	sog.CreateRectangle({ 55.40, 6.47, -13.59 }, { -3.08, -0.33, 0.03 }, { 14.03, 28.39, 0.67 });
	sog.CreateRectangle({ -29.65, -8.14, 76.14 }, { 0.04, 3.03, 0.56 }, { 18.13, 25.57, 0.67 });
	sog.CreateRectangle({ -17.49, -8.45, 83.10 }, { 0.04, 3.10, 1.54 }, { 18.13, 25.57, 0.67 });
	sog.CreateRectangle({ -2.26, -9.13, 77.34 }, { -3.10, -0.01, -0.78 }, { 18.13, 25.57, 0.67 });
	sog.CreateRectangle({ -38.33, -5.66, 40.18 }, { 0.21, -0.05, -2.10 }, { 12.47, 13.44, 0.67 });
	sog.CreateRectangle({ -62.43, -3.70, 35.48 }, { 0.23, -0.02, -2.08 }, { 12.47, 13.44, 0.67 });
	sog.CreateRectangle({ -67.35, -1.27, 27.22 }, { 0.19, 0.17, 3.05 }, { 12.47, 13.44, 0.67 });
	sog.CreateRectangle({ -59.40, 0.44, 21.66 }, { 0.19, 0.32, 1.92 }, { 12.47, 13.44, 0.67 });
	sog.CreateRectangle({ 70.49, -0.15, 15.13 }, { 0.02, -0.10, 2.06 }, { 18.13, 25.57, 0.67 });
	sog.CreateRectangle({ 111.46, 7.70, -70.09 }, { 0.02, -0.03, 0.81 }, { 11.27, 19.19, 0.67 });
	sog.CreateRectangle({ 80.18, 7.52, -75.70 }, { 0.03, -0.00, 0.81 }, { 11.27, 19.19, 0.67 });
	sog.CreateRectangle({ 77.40, 7.52, -109.20 }, { 0.03, -0.00, 0.81 }, { 11.27, 19.19, 0.67 });
	sog.CreateRectangle({ 4.17, 9.37, -111.10 }, { -0.24, 3.12, -0.51 }, { 12.76, 21.74, 0.76 });
	sog.CreateRectangle({ 63.64, 1.93, -31.99 }, { 0.32, -0.43, -1.65 }, { 13.27, 35.77, 0.48 });

	//Checkpoints Spawning
	checkpoints.add(sog.CreateRectangle({ 0,0,0 }, { 0,0,0 }, { 20,20,20 }, 0, true));
	checkpoints.add(sog.CreateRectangle({ 0,0,40 }, { 0,0,0 }, { 20,20,20 }, 0, true));
	checkpoints.add(sog.CreateRectangle({ -20,0,100 }, { 0,0,0 }, { 20,20,20 }, 0, true));

	p2List_item<PhysBody3D*>* a = checkpoints.getFirst();

	while (a != NULL)
	{
		a->data->collision_listeners.add((this));
		a = a->next;
	}

	lose = sog.CreateRectangle({ 0,-20,0 }, { 0,0,0 }, { 1000,1000,10 }, 0, true);
	lose->collision_listeners.add(this);

	//sog.CreateCurve({ 0,0,0 }, { 0,0,0 }, 20, 90);

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	//Uncomment to allow the camera to follow the car
	/*float* carTransform = new float[14];
	App->player->vehicle->GetTransform(carTransform);
	vec3 carPos = { carTransform[12], carTransform[13], carTransform[14] };
	App->camera->LookAt(carPos);*/

	//camera follow the player
	/*btTransform carPos = App->player->vehicle->vehicle->getChassisWorldTransform();
	vec3 initialCarPos = { carPos.getOrigin().getX(),carPos.getOrigin().getY(),carPos.getOrigin().getZ() };
	vec3 carDir = { carPos.getBasis().getColumn(2).getX(),carPos.getBasis().getColumn(2).getY(),carPos.getBasis().getColumn(2).getZ() };
	vec3 cameraPos = initialCarPos - 10 * carDir;
	App->camera->Position = cameraPos;
	App->camera->Reference = initialCarPos;
	App->camera->Position.y = initialCarPos.y + 5;*/

	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	sog.RenderObjects();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	if (body2 == App->player->vehicle)
	{
		if (body1 != lose)
		{
			body1->GetTransform(&spawnPoint);
		}
		else {
			App->player->vehicle->SetTransform(&spawnPoint);
		}
	}
}

SceneObjectGenerator::SceneObjectGenerator(Application* App)
{
	this->App = App;
}

PhysBody3D* SceneObjectGenerator::CreateRectangle(vec3 position, vec3 rotation, vec3 scale, float mass, bool isSensor)
{
	Cube* c = new Cube();
	c->size = scale;
	c->SetRotation((rotation.x + 1.57079633) * 180 / M_PI, rotation.y * 180 / M_PI, rotation.z * 180 / M_PI);
	c->SetPos(position.x, position.y, position.z);
	if(!isSensor)ground.add((Primitive*)c);
	
	return App->physics->AddBody(*c, mass, isSensor);
}

void SceneObjectGenerator::CreateSphere(vec3 position, vec3 rotation, float radius, float mass, bool isSensor)
{
	Sphere* s = new Sphere();
	s->SetRotation(rotation.x, { 1,0,0 });
	s->SetRotation(rotation.y, { 0,1,0 });
	s->SetRotation(rotation.z, { 0,0,1 });
	s->SetPos(position.x, position.y, position.z);
	s->radius = radius;
	if (!isSensor)ground.add((Primitive*)s);

	App->physics->AddBody(*s, mass);
}

void SceneObjectGenerator::CreateCylinder(vec3 position, vec3 rotation, float radius, float height, float mass, bool isSensor)
{
	Cylinder* c = new Cylinder();
	c->SetRotation(rotation.x, { 1,0,0 });
	c->SetRotation(rotation.y, { 0,1,0 });
	c->SetRotation(rotation.z, { 0,0,1 });
	c->SetPos(position.x, position.y, position.z);
	c->radius = radius;
	c->height = height;
	if (!isSensor)ground.add((Primitive*)c);

	App->physics->AddBody(*c, mass);
}

void SceneObjectGenerator::CreateCurve(vec3 position, vec3 rotation, float radius, float targetAngle)
{
	float segmentLength = 2.0;
	float angle = 0;
	int segmentCount = radius * 2;

	for (int i = 0; i <= segmentCount; i++)
	{
		{
			CreateRectangle({ position.x + i * segmentLength / segmentCount * (float)cos((rotation.x + angle) / 2 * 3.1415 / 180) * radius, position.y ,position.z - i * segmentLength / segmentCount * (float)sin((rotation.z + angle) / 2 * 3.1415 / 180) * radius }, { rotation.x,rotation.y + angle,rotation.z }, { segmentLength,1,10 });
			angle += targetAngle / segmentCount;
		}
	}
}

void SceneObjectGenerator::RenderObjects()
{
	p2List_item<Primitive*>* groundSegment = ground.getFirst();
	while (groundSegment != NULL)
	{
		groundSegment->data->Render();
		groundSegment = groundSegment->next;
	}
}
