#ifndef __TITLESCREEN_H__
#define __TITLESCREEN_H__

#include "Module.h"
#include "Globals.h"
#include "p2List.h"
#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;

class TitleScreen : public Module
{
public:

	TitleScreen(bool start_enabled = true);

	// Destructor
	virtual ~TitleScreen();

	// Called before the first frame
	bool Start();

	// Called before all Updates

	// Called each loop iteration
	update_status Update();

	// Called before all Updates

	// Called before quitting
	bool CleanUp();

public:
	uint startSFX = 0;
	SDL_Texture* img;

private:
	

};

#endif // !__TITLE_H__

