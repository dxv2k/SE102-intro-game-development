#include "Sprites.h"
#include "Debug.h"
#include "Game.h"

Sprite::Sprite(	
		int ID, 
		int upper_left_x,  
		int upper_left_y, 
		int bottom_right_x, 
		int bottom_right_y){ 
	this->ID = ID; 
	this->upper_left_x = upper_left_x; 
	this->upper_left_y = upper_left_y; 
	this->bottom_right_x = bottom_right_x; 
	this->bottom_right_y = bottom_right_y; 
}

Sprites* Sprites::__instance = NULL; 

Sprites* Sprites::GetInstance() {
	if (__instance == NULL) {
		__instance = new Sprites(); 
		return __instance; 
	}
}

void Sprite::Draw(float x, float y) {
	Game* game = Game::GetInstance(); 
	game->Draw(
		x, 
		y, 
		texture, 
		upper_left_x,  
		upper_left_y, 
		bottom_right_x, 
		bottom_right_y); 
}

void Sprites::Add(
	int id,
	int upper_left_x,
	int upper_left_y,
	int bottom_right_x,
	int bottom_right_y,
	LPDIRECT3DTEXTURE9 tex) {

	LPSPRITE currentSprite = new Sprite(
		id,
		upper_left_x,
		upper_left_y,
		bottom_right_x,
		bottom_right_y); 

	// Just to remind, already declare in Sprites.h 
	sprites[id] = currentSprite; 
}

LPSPRITE Sprites::Get(int id) {
	return sprites[id]; 
}







