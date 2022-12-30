#ifndef _MODULEWEAPON_H
#define _MODULEWEAPON_H

#include "Entity.h"
#include "Animation.h"
#include "Globals.h"
#include "ModulePhysics.h"
#include "p2Point.h"
#include "vector"
#include "SDL/include/SDL.h"

class ModuleWeapon : public Entity
{
public:
	ModuleWeapon();
	virtual ~ModuleWeapon();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	
	bool CleanUp();

	void AngleHolds();


public:

	int currentweapon = 0;

	//Textures

	//Animations

	bool isDrawn = false;

	bool display = false;

	Animation* currentAnim = nullptr;

	Animation readying;
	Animation idle;
	Animation away;
	Animation putAway;
	Animation aimUp45;
	Animation aimDown45;
	Animation aimDown90;
	Animation aimUp90;
	Animation launchSmoke;

	bool active = false;

	Vec2D position;
	float angle;


private:

	SDL_Texture* texture;
	const char* texturePath;

	bool isFliped = false;
	SDL_RendererFlip fliped = SDL_FLIP_NONE;

};

#endif //MODULEWEAPON
