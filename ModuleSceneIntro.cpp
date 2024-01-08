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

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	//App->camera->LookAt(App->player->initialCarPos);

	// Create sensor cube (will trigger with car)
	/*sensor_cube = App->physics->AddBody(Cube(5, 5, 5), 0.0);
	sensor_cube->SetAsSensor(true);
	sensor_cube->SetPos(0, 3, 0);*/

	sog.CreateRectangle({ 0,0,0 }, { 0,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5,42.5 }, { 45,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5*2,42.5*2 }, { 0,0,0 }, { 10,1,50 });


	//Create sensor
	sog.CreateRectangle({ 0,3,0 }, { 0,0,0 }, { 5,5,5 }, 0, true);
	sog.CreateRectangle({ 0,0,0 }, { 0,0,0 }, { 1000,0,1000 }, 0, true);

	sog.CreateCurve({ 0,0,0 }, { 0,0,0 });

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
}

SceneObjectGenerator::SceneObjectGenerator(Application* App)
{
	this->App = App;
}

PhysBody3D* SceneObjectGenerator::CreateRectangle(vec3 position, vec3 rotation, vec3 scale, float mass, bool isSensor)
{
	Cube* c = new Cube();
	c->size = scale;
	c->SetRotation(rotation.x, rotation.y, rotation.z);
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

void SceneObjectGenerator::CreateCurve(vec3 position, vec3 rotation)
{
	float segmentLength = 2.0;
	float angle = 0;
	int segmentCount = 20;
	int targetAngle = 90;
	int radius = 20;

	for (int i = 0; i <= segmentCount; i++)
	{
		{
			CreateRectangle({ position.x + i * segmentLength / segmentCount * (float)cos(angle / 2 * 3.1415 / 180) * radius, position.y ,position.z - i * segmentLength / segmentCount * (float)sin(angle / 2 * 3.1415 / 180) * radius}, {0,angle,0}, {segmentLength,1,10});
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
