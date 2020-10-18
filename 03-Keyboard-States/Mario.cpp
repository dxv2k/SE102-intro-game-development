#include "Mario.h"

void CMario::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	vy += MARIO_GRAVITY;
	if (y > 100) 
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CMario::Render()
{
	//// Original Code	
	//int ani;
	//if (vx == 0)
	//{
	//	if (nx > 0) ani = MARIO_ANI_IDLE_RIGHT;
	//	else ani = MARIO_ANI_IDLE_LEFT;
	//}
	//else if (vx > 0)
	//	ani = MARIO_ANI_WALKING_RIGHT;
	//else ani = MARIO_ANI_WALKING_LEFT;
	int ani; 

	if (status == MARIO_SMALL)
	{
		if (vx == 0)
		{
			if (nx > 0)
			{
				ani = MARIO_ANI_IDLE_RIGHT;
			}
			else
			{
				ani = MARIO_ANI_IDLE_LEFT;
			}
		}
		else if (vx > 0)
		{
			ani = MARIO_ANI_WALKING_RIGHT;
		}
		else
		{
			ani = MARIO_ANI_WALKING_LEFT;
		}

		if (y < 100)
		{
			if (nx > 0)
			{
				ani = MARIO_ANI_JUMP_RIGHT;
			}
			else
			{
				ani = MARIO_ANI_JUMP_LEFT;
			}
		}
	}

	if (status == MARIO_BIG)
	{
		if (vx == 0)
		{
			if (nx > 0)
			{
				ani = MARIO_BIG_ANI_IDLE_RIGHT;
			}
			else
			{
				ani = MARIO_BIG_ANI_IDLE_LEFT;
			}
		}
		else if (vx > 0)
		{
			ani = MARIO_BIG_ANI_WALKING_RIGHT;
		}
		else
		{
			ani = MARIO_BIG_ANI_WALKING_LEFT;
		}

		if (y < 100)
		{
			if (nx > 0)
			{
				ani = MARIO_BIG_ANI_JUMP_RIGHT;
			}
			else
			{
				ani = MARIO_BIG_ANI_JUMP_LEFT;
			}
		}

		if (state == MARIO_STATE_SIT)
		{
			if (nx > 0)
			{
				ani = MARIO_BIG_ANI_SIT_RIGHT;
			}
			else
			{
				ani = MARIO_BIG_ANI_SIT_LEFT;
			}
		}
	}

	if (status == MARIO_RACOON)
	{
		if (vx == 0)
		{
			if (nx > 0)
			{
				ani = MARIO_RACOON_ANI_IDLE_RIGHT;
			}
			else
			{
				ani = MARIO_RACOON_ANI_IDLE_LEFT;
			}
		}
		else if (vx > 0)
		{
			ani = MARIO_RACOON_ANI_WALKING_RIGHT;
		}
		else
		{
			ani = MARIO_RACOON_ANI_WALKING_LEFT;
		}

		if (y < 100)
		{
			if (nx > 0)
			{
				ani = MARIO_RACOON_ANI_JUMP_RIGHT;
			}
			else
			{
				ani = MARIO_RACOON_ANI_JUMP_LEFT;
			}
		}

		if (state == MARIO_STATE_SIT)
		{
			if (nx > 0)
			{
				ani = MARIO_RACOON_ANI_SIT_RIGHT;
			}
			else
			{
				ani = MARIO_RACOON_ANI_SIT_LEFT;
			}
		}

		if (state == MARIO_STATE_HIT_TAIL)
		{
			if (nx > 0)
			{
				ani = MARIO_RACOON_ANI_HIT_TAIL_RIGHT;
			}
			else
			{
				ani = MARIO_RACOON_ANI_HIT_TAIL_LEFT;
			}
		}
	}

	if (status == MARIO_FIRE)
	{
		if (vx == 0)
		{
			if (nx > 0)
				ani = MARIO_FIRE_ANI_IDLE_RIGHT;
			else
				ani = MARIO_FIRE_ANI_IDLE_LEFT;
		}
		else if (vx > 0)
			ani = MARIO_FIRE_ANI_WALKING_RIGHT;
		else
			ani = MARIO_FIRE_ANI_WALKING_LEFT;

		if (y < 100)
		{
			if (nx > 0)
				ani = MARIO_FIRE_ANI_JUMP_RIGHT;
			else
				ani = MARIO_FIRE_ANI_JUMP_LEFT;
		}

		if (state == MARIO_STATE_SIT)
		{
			if (nx > 0)
				ani = MARIO_FIRE_ANI_SIT_RIGHT;
			else
				ani = MARIO_FIRE_ANI_SIT_LEFT;
		}

		if (state == MARIO_STATE_SHOOT_FIRE)
		{
			if (nx > 0)
				ani = MARIO_FIRE_ANI_SHOOT_RIGHT;
			else
				ani = MARIO_FIRE_ANI_SHOOT_LEFT;
		}
	}


	animations[ani]->Render(x, y);
	
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT: 
		vx = -MARIO_WALKING_SPEED;
		nx = -1;
		break;
	case MARIO_STATE_RUNNING_LEFT:
		vx = -MARIO_RUNNING_SPEED;
		nx = -1;
		break;
	case MARIO_STATE_RUNNING_RIGHT:
		vx = MARIO_RUNNING_SPEED;
		nx = 1;
		break;
	case MARIO_STATE_JUMP: 
		if (y==100)
			vy = -MARIO_JUMP_SPEED_Y;
	case MARIO_STATE_IDLE: 
		vx = 0;
		break;
	}
}

CMario::CMario() {
	status = MARIO_SMALL; 
	//status = MARIO_BIG; 
	//status = MARIO_RACOON; 
	//status = MARIO_STAR; 
}

