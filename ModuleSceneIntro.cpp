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

	//sog.CreateRectangle({ 56.09, 16.94, 15.70 }, { -0.04, -0.05, -0.12 }, { 94.89, 60.16, 69.89 });
	sog.CreateRectangle({ 56.09, 16.94, 15.70 }, { -0.04, -0.05, -0.12 }, { 1.16, 9.30, 0.39 });
	sog.CreateRectangle({ 1.64, -2.63, 28.78 }, { 3.14, 0.00, 0.00 }, { 22.46, 109.90, -0.83 });
	sog.CreateRectangle({ 71.88, -2.43, 77.90 }, { 3.14, -0.00, 0.00 }, { 22.46, 30.80, -0.83 });
	sog.CreateRectangle({ 1.64, -2.09, 28.78 }, { 0.00, 0.00, 0.00 }, { 22.46, 109.90, 0.83 });
	sog.CreateRectangle({ 1.64, -2.63, 28.78 }, { 3.14, 0.00, 0.00 }, { 22.46, 109.90, -0.83 });
	sog.CreateRectangle({ 1.64, -2.63, 28.78 }, { 3.14, 0.00, 0.00 }, { 22.46, 109.90, -0.83 });
	sog.CreateRectangle({ 1.64, -2.63, 28.78 }, { 3.14, 0.00, 0.00 }, { 22.46, 109.90, -0.83 });
	sog.CreateRectangle({ 4.88, 9.92, 21.52 }, { 0.00, -0.00, -1.57 }, { 16.43, 147.73, 0.60 });
	sog.CreateRectangle({ -44.20, 1.00, 67.16 }, { 0.10, 2.98, 0.04 }, { 22.47, 44.15, 0.83 });
	sog.CreateRectangle({ -65.09, 3.75, 42.32 }, { 0.05, -3.03, 1.46 }, { 15.44, 24.20, 0.83 });
	sog.CreateRectangle({ 137.96, 19.70, -41.49 }, { -0.01, -3.11, -0.02 }, { 22.46, 87.40, 0.83 });
	sog.CreateRectangle({ 95.28, 18.22, -117.71 }, { -0.03, -3.12, -0.02 }, { 22.46, 33.43, 0.83 });
	sog.CreateRectangle({ 50.43, 21.10, -142.94 }, { 3.04, -0.02, 1.55 }, { 14.50, 81.60, 0.83 });
	sog.CreateRectangle({ 1.80, 27.47, -120.08 }, { -0.29, 3.08, -0.02 }, { 21.91, 33.44, 0.83 });
	sog.CreateRectangle({ 2.14, 41.60, -81.30 }, { -0.39, 3.08, -0.03 }, { 21.92, 52.24, 0.83 });
	sog.CreateRectangle({ 116.45, 18.98, -93.13 }, { -3.12, -0.03, 1.55 }, { 13.95, 23.77, 0.83 });
	sog.CreateRectangle({ 101.08, 18.82, 4.25 }, { 3.12, 0.09, 1.41 }, { 14.83, -88.40, 0.83 });
	sog.CreateRectangle({ 91.54, 5.99, -14.05 }, { -3.07, 0.08, 0.01 }, { 20.19, 48.30, 0.83 });
	sog.CreateRectangle({ 67.22, 17.45, -21.08 }, { -2.97, -0.33, -0.01 }, { 17.37, 35.16, 0.83 });
	sog.CreateRectangle({ -38.11, -0.64, 90.04 }, { 0.04, 3.03, 0.56 }, { 22.46, 31.67, 0.83 });
	sog.CreateRectangle({ -23.05, -1.02, 98.66 }, { 0.04, 3.10, 1.54 }, { 22.46, 31.67, 0.83 });
	sog.CreateRectangle({ -4.19, -1.87, 91.53 }, { -3.10, -0.01, -0.78 }, { 22.46, 31.67, 0.83 });
	sog.CreateRectangle({ -48.86, 2.43, 45.51 }, { 0.21, -0.05, -2.10 }, { 15.44, 16.65, 0.83 });
	sog.CreateRectangle({ -78.71, 4.86, 39.69 }, { 0.23, -0.02, -2.08 }, { 15.44, 16.65, 0.83 });
	sog.CreateRectangle({ -84.80, 7.86, 29.46 }, { 0.19, 0.17, 3.05 }, { 15.44, 16.65, 0.83 });
	sog.CreateRectangle({ -74.95, 9.98, 22.57 }, { 0.19, 0.32, 1.92 }, { 15.44, 16.65, 0.83 });
	sog.CreateRectangle({ 85.90, 8.27, 14.49 }, { 0.05, -0.23, 2.05 }, { 22.46, 31.67, 0.83 });
	sog.CreateRectangle({ 80.35, 9.27, -42.43 }, { -0.43, 0.07, 1.39 }, { 22.46, 31.67, 0.83 });
	sog.CreateRectangle({ 136.63, 18.98, -91.05 }, { 0.02, -0.03, 0.81 }, { 13.95, 23.77, 0.83 });
	sog.CreateRectangle({ 97.90, 18.75, -98.00 }, { 0.03, -0.00, 0.81 }, { 13.95, 23.77, 0.83 });
	sog.CreateRectangle({ 94.46, 18.75, -139.48 }, { 0.03, -0.00, 0.81 }, { 13.95, 23.77, 0.83 });
	sog.CreateRectangle({ 4.64, 18.75, -141.48 }, { -0.01, -0.03, 2.53 }, { 15.81, 26.92, 0.94 });








	//Create sensor
	//sog.CreateRectangle({ 0,3,0 }, { 0,0,0 }, { 5,5,5 }, 0, true);
	//lose = sog.CreateRectangle({ 0,-10,0 }, { 0,0,0 }, { 1000,0,1000 }, 0, true);

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
