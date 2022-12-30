#include "Globals.h"
#include "Application.h"
#include "ModuleWeapon.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "FadeToBlack.h" 
#include "ModuleEntityManager.h"
#include "Entity.h"
#include "ModuleSceneIntro.h"


ModuleWeapon::ModuleWeapon() : Entity(EntityType::WEAPON) {
	name.Create("ModuleWeapon");
}

ModuleWeapon::~ModuleWeapon()
{}

// Load assets
bool ModuleWeapon::Start()
{
	LOG("Loading Weapon");

	texture = app->textures->Load("Assets/Textures/Worms_spritesheet_full.png");

	//Animations
	readying.PushBack({ 93, 112, 28, 28 });
	readying.PushBack({ 93, 140, 28, 28 });
	readying.PushBack({ 93, 168, 28, 28 });
	readying.loop = false;
	readying.speed = 0.1f;

	idle.PushBack({ 97, 171, 24, 15 });
	idle.loop = true;
	idle.speed = 0.05f;

	away.PushBack({ 5, 244, 24, 15 });
	away.loop = true;
	away.speed = 0.05f;

	putAway.PushBack({ 93, 168, 28, 28 });
	putAway.PushBack({ 93, 196, 28, 28 });
	putAway.PushBack({ 93, 224, 28, 28 });
	putAway.loop = false;
	putAway.speed = 0.1f;

	aimUp45.PushBack({ 93, 140, 28, 28 });
	aimUp45.loop = true;
	aimUp45.speed = 0.1f;

	aimDown45.PushBack({ 93, 196, 28, 28 });
	aimDown45.loop = true;
	aimDown45.speed = 0.1f;

	aimUp90.PushBack({ 93,112,28,28 });
	aimUp90.loop = true;
	aimUp90.speed = 0.1f;

	aimDown90.PushBack({ 93, 224, 28, 28 });
	aimDown90.loop = true;
	aimDown90.speed = 0.1f;

	launchSmoke.PushBack({ 73, 313, 34, 35 });
	launchSmoke.PushBack({ 107, 315, 20, 29 });
	launchSmoke.PushBack({ 126, 319, 14, 19 });
	launchSmoke.PushBack({ 73, 313, 34, 35 });
	launchSmoke.PushBack({ 107, 315, 20, 29 });
	launchSmoke.PushBack({ 126, 319, 14, 19 });
	launchSmoke.loop = false;
	launchSmoke.speed = 0.05f;

	currentAnim = &away;


	LOG("CREATES Weapon");

	return true;
}

// Unload assets
bool ModuleWeapon::CleanUp()
{
	LOG("Unloading Weapon");

	return true;
}


update_status ModuleWeapon::PreUpdate()
{
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleWeapon::Update() {

	currentAnim = &idle;
	
	//Weapon Movement P1
	if (app->scene_intro->player->isTurn == true) {
		
		if (app->scene_intro->player->fliped == SDL_FLIP_NONE) {
			position.x = app->scene_intro->player->pbody->x - app->scene_intro->player->pbody->radius*2;
			position.y = app->scene_intro->player->pbody->y + app->scene_intro->player->pbody->radius/3;
			angle = -app->scene_intro->player->projAngle + 180.0f;
			fliped = SDL_FLIP_NONE;
		}
		if (app->scene_intro->player->fliped == SDL_FLIP_HORIZONTAL) {
			position.x = app->scene_intro->player->pbody->x;
			position.y = app->scene_intro->player->pbody->y + app->scene_intro->player->pbody->radius/3;
			angle = -app->scene_intro->player->projAngle;
			fliped = SDL_FLIP_HORIZONTAL;
		}
		
	}
	//Weapon Movement P2
	if (app->scene_intro->playertwo->isTurn == true) {

		if (app->scene_intro->playertwo->fliped == SDL_FLIP_NONE) {
			position.x = app->scene_intro->playertwo->pbody->x - app->scene_intro->playertwo->pbody->radius * 2;
			position.y = app->scene_intro->playertwo->pbody->y + app->scene_intro->playertwo->pbody->radius / 3;
			angle = -app->scene_intro->playertwo->projAngle + 180.0f;
			fliped = SDL_FLIP_NONE;
		}
		if (app->scene_intro->playertwo->fliped == SDL_FLIP_HORIZONTAL) {
			position.x = app->scene_intro->playertwo->pbody->x;
			position.y = app->scene_intro->playertwo->pbody->y + app->scene_intro->playertwo->pbody->radius / 3;
			angle = -app->scene_intro->playertwo->projAngle;
			fliped = SDL_FLIP_HORIZONTAL;
		}

	}
	//Weapon Movement P3
	if (app->scene_intro->playerthree->isTurn == true) {

		if (app->scene_intro->playerthree->fliped == SDL_FLIP_NONE) {
			position.x = app->scene_intro->playerthree->pbody->x - app->scene_intro->playertwo->pbody->radius * 2;
			position.y = app->scene_intro->playerthree->pbody->y + app->scene_intro->playertwo->pbody->radius / 3;
			angle = -app->scene_intro->playerthree->projAngle + 180.0f;
			fliped = SDL_FLIP_NONE;
		}
		if (app->scene_intro->playerthree->fliped == SDL_FLIP_HORIZONTAL) {
			position.x = app->scene_intro->playerthree->pbody->x;
			position.y = app->scene_intro->playerthree->pbody->y + app->scene_intro->playerthree->pbody->radius / 3;
			angle = -app->scene_intro->playerthree->projAngle;
			fliped = SDL_FLIP_HORIZONTAL;
		}

	}
	//Weapon Movement P4
	if (app->scene_intro->playerfour->isTurn == true) {

		if (app->scene_intro->playerfour->fliped == SDL_FLIP_NONE) {
			position.x = app->scene_intro->playerfour->pbody->x - app->scene_intro->playerfour->pbody->radius * 2;
			position.y = app->scene_intro->playerfour->pbody->y + app->scene_intro->playerfour->pbody->radius / 3;
			angle = -app->scene_intro->playerfour->projAngle + 180.0f;
			fliped = SDL_FLIP_NONE;
		}
		if (app->scene_intro->playerfour->fliped == SDL_FLIP_HORIZONTAL) {
			position.x = app->scene_intro->playerfour->pbody->x;
			position.y = app->scene_intro->playerfour->pbody->y + app->scene_intro->playerfour->pbody->radius / 3;
			angle = -app->scene_intro->playerfour->projAngle;
			fliped = SDL_FLIP_HORIZONTAL;
		}

	}

	SDL_Rect rect = currentAnim->GetCurrentFrame();
	app->renderer->Blit(texture, METERS_TO_PIXELS(position.x), SCREEN_HEIGHT - METERS_TO_PIXELS(position.y), &rect, fliped, angle);
	currentAnim->Update();


	return UPDATE_CONTINUE;
}


update_status ModuleWeapon::PostUpdate()
{
	return UPDATE_CONTINUE;
}

//void ModuleWeapon::AngleHolds() {
//
//	//P1
//	if (app->scene_intro->player->isTurn == true) {
//		angleholder1 = app->scene_intro->player->projAngle;
//	}
//	if (app->scene_intro->playertwo->isTurn == true) {
//		angleholder1 = app->scene_intro->playertwo->projAngle;
//	}
//
//	if (angleholder1 == 90 || angleholder1 == 85 || angleholder1 == 80 || angleholder1 == 75 || angleholder1 == 70) {
//		currentAnim = &aimUp90;
//	}
//	if (angleholder1 == 65 || angleholder1 == 60 || angleholder1 == 55 || angleholder1 == 50 || angleholder1 == 45 ||
//		angleholder1 == 40 || angleholder1 == 35 || angleholder1 == 30 || angleholder1 == 25 || angleholder1 == 20) {
//		currentAnim = &aimUp45;
//	}
//	if (angleholder1 == 15 || angleholder1 == 10 || angleholder1 == 5 || angleholder1 == 0 || angleholder1 == -5 ||
//		angleholder1 == -10 || angleholder1 == -15 || angleholder1 == -20 || angleholder1 == -25 || angleholder1 == -30) {
//		currentAnim = &idle;
//	}
//	if (angleholder1 == -35 || angleholder1 == -40 || angleholder1 == -45 || angleholder1 == -50 ||
//		angleholder1 == -55 || angleholder1 == -60 || angleholder1 == -65 || angleholder1 == -70) {
//		currentAnim = &aimDown45;
//	}
//	if (angleholder1 == -75 || angleholder1 == -80 || angleholder1 == -85 || angleholder1 == -90) {
//		currentAnim = &aimDown90;
//	}
//
//	if (angleholder1 == 90 || angleholder1 == 95 || angleholder1 == 100 || angleholder1 == 105 || angleholder1 == 110) {
//		currentAnim = &aimUp90;
//	}
//	if (angleholder1 == 115 || angleholder1 == 120 || angleholder1 == 125 || angleholder1 == 130 || angleholder1 == 135 ||
//		angleholder1 == 140 || angleholder1 == 145 || angleholder1 == 150 || angleholder1 == 155 || angleholder1 == 160) {
//		currentAnim = &aimUp45;
//	}
//	if (angleholder1 == 165 || angleholder1 == 170 || angleholder1 == 175 || angleholder1 == 180 || angleholder1 == 185 ||
//		angleholder1 == 190 || angleholder1 == 195 || angleholder1 == 200 || angleholder1 == 205 || angleholder1 == 210) {
//		currentAnim = &idle;
//	}
//	if (angleholder1 == 215 || angleholder1 == 220 || angleholder1 == 225 || angleholder1 == 230 ||
//		angleholder1 == 235 || angleholder1 == 240 || angleholder1 == 245 || angleholder1 == 250) {
//		currentAnim = &aimDown45;
//	}
//	if (angleholder1 == 270 || angleholder1 == 265 || angleholder1 == 260 || angleholder1 == 255) {
//		currentAnim = &aimDown90;
//	}
//
//	//P2
//}