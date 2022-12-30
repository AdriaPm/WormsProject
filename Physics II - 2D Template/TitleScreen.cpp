#include "TitleScreen.h"
#include "Application.h"
#include "Animation.h"
#include "ModuleWindow.h"
#include "ModuleAudio.h"
#include "Fonts.h"
#include "ModuleInput.h"
#include "ModulePhysics.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleTextures.h"
#include "UI.h"
#include "FadeToBlack.h"
#include "ModulePlayer.h"


#include "SDL/include/SDL_render.h"

TitleScreen::TitleScreen(bool start_enabled) : Module(start_enabled)
{
	name.Create("ModuleTitleScreen");
}

// Destructor
TitleScreen::~TitleScreen()
{}

// Called before the first frame
bool TitleScreen::Start()
{
	LOG("Loading TitleScreen");
	bool ret = true;

	//Disable modules/entities
	

	// Set camera position
	app->renderer->camera.x = app->renderer->camera.y = 0;

	//Load music
	app->audio->PlayMusic("Assets/Audio/Music/TitleScreen.ogg");
	
	//Load SFX
	startSFX = app->audio->LoadFx("Assets/Audio/Fx/start_game.wav");

	//Load tex
	img = app->textures->Load("Assets/Textures/TitleScreen.png");


	return ret;
}

// Called each loop iteration
update_status TitleScreen::Update()
{
	// Enable/Disable Fullscreen Mode
	if (app->input->GetKey(SDL_SCANCODE_F11) == KEY_DOWN)
		app->fullscreen = !app->fullscreen;

	//Pass next screen
	if (app->input->GetKey(SDL_SCANCODE_RETURN) == KEY_DOWN) {
		LOG("PASA A GAME SCENE");
		app->fade->FadeBlack(this, (Module*)app->scene_intro, 100);
		app->audio->PlayFx(startSFX);
	}

	if (app->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		return UPDATE_STOP;

	app->renderer->Blit(img, 0, 0, NULL);

	return UPDATE_CONTINUE;
}

// Called before quitting
bool TitleScreen::CleanUp()
{
	LOG("Unloading Title scene");

	app->textures->Unload(img);
	return true;
}
