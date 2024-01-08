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

	/*sog.CreateRectangle({ 0,0,0 }, { 0,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5,42.5 }, { 45,0,0 }, { 10,1,50 });
	sog.CreateRectangle({ 0,-17.5*2,42.5*2 }, { 0,0,0 }, { 10,1,50 });*/

	sog.CreateRectangle({ 0.12, -16.29, -4.20 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -36.52, -12.45, -14.99 }, { 0.00, -0.00, 0.00 }, { 2.26, 2.26, 2.26 });
	sog.CreateRectangle({ 0.33, -15.12, -4.13 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.51, -13.95, -4.05 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.66, -12.77, -3.96 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.80, -11.59, -3.86 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.92, -10.41, -3.76 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.03, -9.23, -3.65 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.13, -8.05, -3.55 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.21, -6.86, -3.44 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.29, -5.68, -3.33 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.36, -4.50, -3.22 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.40, -3.31, -3.11 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.44, -2.13, -3.00 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.48, -0.95, -2.88 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.49, 0.24, -2.77 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.48, 1.42, -2.65 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.47, 2.61, -2.53 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.45, 3.79, -2.41 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.41, 4.98, -2.29 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.32, 6.16, -2.16 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.24, 7.34, -2.04 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.15, 8.52, -1.91 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 1.02, 9.69, -1.78 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.84, 10.86, -1.65 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.65, 12.03, -1.52 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.46, 13.20, -1.38 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ 0.20, 14.35, -1.24 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -0.14, 15.48, -1.10 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -0.48, 16.61, -0.96 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -0.89, 17.71, -0.81 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -1.41, 18.77, -0.66 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -1.98, 19.80, -0.51 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -2.65, 20.75, -0.35 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -3.49, 21.58, -0.20 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -4.39, 22.33, -0.04 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -5.42, 22.82, 0.10 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -6.58, 23.07, 0.22 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -7.74, 23.19, 0.30 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -8.90, 23.04, 0.31 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -10.05, 22.77, 0.28 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -11.19, 22.44, 0.21 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -12.26, 21.97, 0.06 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -13.30, 21.42, -0.14 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -14.34, 20.88, -0.33 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -15.35, 20.30, -0.55 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -16.31, 19.65, -0.82 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -17.25, 18.97, -1.10 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -18.19, 18.29, -1.38 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -19.12, 17.62, -1.66 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -20.03, 16.91, -1.96 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -20.90, 16.16, -2.29 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -21.77, 15.42, -2.62 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -22.63, 14.67, -2.95 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -23.50, 13.92, -3.28 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -24.35, 13.16, -3.61 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -25.18, 12.38, -3.97 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -25.99, 11.59, -4.33 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -26.81, 10.81, -4.69 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -27.63, 10.02, -5.05 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -28.45, 9.23, -5.41 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -29.25, 8.43, -5.78 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -30.03, 7.62, -6.16 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -30.81, 6.81, -6.54 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -31.59, 5.99, -6.92 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -32.38, 5.18, -7.30 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -33.16, 4.37, -7.69 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -33.92, 3.55, -8.08 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -34.68, 2.72, -8.47 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -35.44, 1.89, -8.87 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -36.20, 1.07, -9.27 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -36.96, 0.24, -9.67 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -37.71, -0.59, -10.07 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -38.46, -1.42, -10.48 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -39.21, -2.25, -10.89 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -39.95, -3.09, -11.30 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -40.69, -3.92, -11.71 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -41.44, -4.75, -12.12 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -42.18, -5.59, -12.54 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -42.92, -6.42, -12.96 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -43.65, -7.25, -13.39 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -44.39, -8.09, -13.81 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -45.13, -8.92, -14.24 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -45.87, -9.74, -14.67 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -46.61, -10.56, -15.11 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -47.36, -11.38, -15.55 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -48.10, -12.19, -15.99 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -48.87, -12.99, -16.45 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -49.64, -13.77, -16.91 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -50.43, -14.52, -17.38 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -51.28, -15.19, -17.87 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -52.20, -15.73, -18.39 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -53.17, -16.16, -18.93 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -54.10, -16.66, -19.47 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -55.01, -17.21, -20.00 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -55.91, -17.78, -20.54 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -56.79, -18.38, -21.06 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -57.66, -19.01, -21.59 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -58.52, -19.64, -22.11 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -59.38, -20.28, -22.64 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -60.23, -20.93, -23.16 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -61.07, -21.60, -23.67 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -61.91, -22.26, -24.19 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -62.75, -22.93, -24.71 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -63.58, -23.61, -25.22 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -64.41, -24.30, -25.73 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -65.23, -24.98, -26.24 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -66.06, -25.67, -26.75 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -66.89, -26.36, -27.26 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -67.71, -27.06, -27.77 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -68.53, -27.76, -28.27 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -69.35, -28.46, -28.78 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -70.17, -29.16, -29.28 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -70.99, -29.86, -29.78 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -71.81, -30.57, -30.28 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -72.62, -31.27, -30.78 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -73.44, -31.98, -31.28 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -74.26, -32.69, -31.77 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -75.08, -33.40, -32.27 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -75.90, -34.11, -32.76 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -76.73, -34.81, -33.25 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -77.55, -35.52, -33.73 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -78.38, -36.23, -34.21 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -79.21, -36.93, -34.69 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -80.05, -37.63, -35.17 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -80.90, -38.32, -35.63 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });
	sog.CreateRectangle({ -81.75, -39.02, -36.10 }, { 0.00, -0.00, 0.00 }, { 0.25, 3.05, 0.11 });



	//Create sensor
	sog.CreateRectangle({ 0,3,0 }, { 0,0,0 }, { 5,5,5 }, 0, true);
	//lose = sog.CreateRectangle({ 0,-10,0 }, { 0,0,0 }, { 1000,0,1000 }, 0, true);

	sog.CreateCurve({ 0,0,0 }, { 0,45,0 }, 20, 90);

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
