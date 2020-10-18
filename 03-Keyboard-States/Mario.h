#pragma once
#include "GameObject.h"

#define MARIO_WALKING_SPEED		0.1f
#define MARIO_RUNNING_SPEED		0.4f  // Test running 
#define MARIO_JUMP_SPEED_Y		0.5f
#define MARIO_GRAVITY			0.1f

// All Mario status shared the same state
#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300
#define MARIO_STATE_RUNNING_LEFT	400 // Test running
#define MARIO_STATE_RUNNING_RIGHT	500 // Test running

#define SMALL_MARIO_ANI_IDLE_RIGHT		4
#define SMALL_MARIO_ANI_IDLE_LEFT			5
#define SMALL_MARIO_ANI_WALKING_RIGHT		6
#define SMALL_MARIO_ANI_WALKING_LEFT		7

#define MARIO_ANI_IDLE_RIGHT		0
#define MARIO_ANI_IDLE_LEFT			1
#define MARIO_ANI_WALKING_RIGHT		2
#define MARIO_ANI_WALKING_LEFT		3


// Mario status
#define SMALL_MARIO 10 
#define SUPER_MARIO 11 // Also Mario in this testing version
#define FIRE_MARIO 12
#define RACCOON_MARIO 13 
#define INVINCIBLE_MARIO 14 

class CMario : public CGameObject
{
public: 

	void Update(DWORD dt);
	void Render();
	void SetState(int state);

	// For debugging chaning status of Mario character  
	void SetStatus(int status); 
};