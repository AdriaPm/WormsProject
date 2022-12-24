#ifndef _MODULEPLAYER_H
#define _MODULEPLAYER_H

#include "Entity.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "vector"
#include "SDL/include/SDL.h"

struct Object
{
	SDL_Texture* graphic;
	uint fx;

	Object() : graphic(NULL)
	{}
};

class ModulePlayer : public Entity
{
public:
	ModulePlayer();
	virtual ~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	void Attack();

	bool CleanUp();

public:

	//Textures

	//Animations

	Animation* currentAnim = nullptr;

	Animation idlePlayer;
	Animation IdleBandanaPlayer;
	Animation attackrdyPlayer;

	//Collider Player
	/*Collider* collider = nullptr;*/

	bool godMode = false;

	//bool isDefeated = false;
	//bool isCelebrating = false;

	bool onGround = false;
	bool dead = false;
	bool onCollision = false; 
	bool attackrdy = false;

	//Turn bool to decide if is users shoot turn
	bool isTurn;

	int hp;

	int x;
	int y;

	Vec2D velocity = { x, y };
	Vec2D startPos = { x, y };

private:

	SDL_Texture* texture;
	const char* texturePath;

};

#endif //MODULEPLAYER