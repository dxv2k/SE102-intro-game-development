#pragma once

#include "GameObject.h"


#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.4f  // Test running 
#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_GRAVITY			0.1f

#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RUNNING_LEFT	400 // Test running
#define MARIO_STATE_RUNNING_RIGHT	500 // Test running


// This for vector Animations
// Remember to load textures exactly like this order 
#define MARIO_ANI_IDLE_RIGHT		0
#define MARIO_ANI_IDLE_LEFT			1
#define MARIO_ANI_WALKING_RIGHT		2
#define MARIO_ANI_WALKING_LEFT		3


class Mario : public GameObject {
public: 
	void Update(DWORD dt); 
	void Render(); 
	void SetState(int state); 
};



