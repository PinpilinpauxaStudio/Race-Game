#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 2, 5);
	car.chassis_offset.Set(0, 1.5, 0);
	car.mass = 500.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;


	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->collision_listeners.add(this); // Add this module as listener to callbacks from vehicle
	vehicle->SetPos(0, 12, 10);

	carPos = vehicle->vehicle->getChassisWorldTransform();
	initialCarPos = { carPos.getOrigin().getX(),carPos.getOrigin().getY(),carPos.getOrigin().getZ() };
	
	accelerationFx = App->audio->LoadFx("Audio/acceleration.ogg");
	brakeFx = App->audio->LoadFx("Audio/brake.ogg");

	vehicle->GetTransform(&App->scene_intro->spawnPoint);

	initmass = 500.0f;
	initgrav = -10.0f;
	initfric = 50.5f;
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	acceleration = brake = 0.0f;

	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT) {
		LOG("mass: %f", vehicle->info.mass)
		vehicle->info.mass += 100.0f;
	}
	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		LOG("mass: %f", vehicle->info.mass)
		if(vehicle->info.mass > 100.0f) vehicle->info.mass -= 100.0f;
	}
	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN) {
		LOG("gravity: %f", g.getY())
		val += 5.0f;
		g.setY(val);
	}
	if (App->input->GetKey(SDL_SCANCODE_G) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN) {
		LOG("gravity: %f", g.getY())
		val -= 5.0f;
		g.setY(val);
	}
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT) {
		LOG("friction: %f", vehicle->info.frictionSlip)
		vehicle->info.frictionSlip += 10.0f; 
	}
	if (App->input->GetKey(SDL_SCANCODE_F) == KEY_REPEAT && App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT) {
		LOG("friction: %f", vehicle->info.frictionSlip)
		vehicle->info.frictionSlip -= 10.0f;
		if (vehicle->info.frictionSlip <= 0) vehicle->info.frictionSlip = 0;
	}

	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
	{
		acceleration = MAX_ACCELERATION;
		if (!accelerationSoundPlayed) {
			App->audio->PlayFx(accelerationFx);
			accelerationSoundPlayed = true;
		}
	}
	if(App->input->GetKey(SDL_SCANCODE_W) == KEY_UP) accelerationSoundPlayed = false;

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES * dt * 5;
	}
	else {
		if (turn > 0)
		{
			turn -= TURN_DEGREES * dt * 5;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES * dt * 5;
	}
	else {
		if (turn < 0)
		{
			turn += TURN_DEGREES / 100;
		}
	}

	if(App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
	{
		acceleration = -MAX_ACCELERATION;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
	{
		brake = BRAKE_POWER;
		if (!brakeSoundPlayed) {
			App->audio->PlayFx(brakeFx);
			brakeSoundPlayed = true; 
		}
	}
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_UP) brakeSoundPlayed = false;

	if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_UP) this->vehicle->SetTransform(&App->scene_intro->spawnPoint);

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	char title[80];
	sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
	App->window->SetTitle(title);

	CameraFollow(dt);
	/*if (carPos.getOrigin().getY() <= -20) {
		vehicle->SetPos(0, 12, 10);
;		acceleration = brake = 0.0f;
	}*/

	return UPDATE_CONTINUE;
}

void ModulePlayer::CameraFollow(float dt)
{
	carPos = vehicle->vehicle->getChassisWorldTransform();
	initialCarPos = { carPos.getOrigin().getX(),carPos.getOrigin().getY(),carPos.getOrigin().getZ()};
	carDir = { carPos.getBasis().getColumn(2).getX(),carPos.getBasis().getColumn(2).getY(),carPos.getBasis().getColumn(2).getZ() };
	cameraPos = initialCarPos - 10 * carDir;
	//btVector3 lerpedCamPos = lerp({ oldCameraPos.x, oldCameraPos.y, oldCameraPos.z }, { cameraPos.x, cameraPos.y, cameraPos.z }, dt * 400);
	//oldCameraPos = { lerpedCamPos.getX(), lerpedCamPos.getY(), lerpedCamPos.getZ()};
	//App->camera->Position = oldCameraPos;
	App->camera->Position = cameraPos;
	App->camera->Reference = initialCarPos;
	App->camera->Position.y += 5;

}

void ModulePlayer::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	// Randomly teleport the sensor cube around 1st quadrant
	if (body1->is_sensor)	body1->SetPos(20 * rand() / RAND_MAX, 3, 20 * rand() / RAND_MAX);
	if (body2->is_sensor)	body2->SetPos(20 * rand() / RAND_MAX, 3, 20 * rand() / RAND_MAX);
}

