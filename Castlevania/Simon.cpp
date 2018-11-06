#include "Simon.h"


void Simon::Update(DWORD dt)
{
	GameObject::Update(dt);
	vy += SIMON_GRAVITY;
	if (y > 100)
	{
		vy = 0;
		y = 100.0f;
	}

	
	if (vx > 0 && x > 290)
	{
		x = 290;
	}
	if (vx < 0 && x < 0)
	{
		x = 0;
	}
}

void Simon::Render()
{
	int ani;
	if (state == SIMON_STATE_FIGHT)
	{
		if (nx > 0)
		{
			ani = SIMON_ANI_FIGHT_RIGHT;
		}
		else
		{
			ani = SIMON_ANI_FIGHT_LEFT;
		}
	}
	else if (state == SIMON_STATE_JUMP)
	{
		if(nx > 0)
		{
			ani = SIMON_ANI_JUMP_RIGHT;
		}
		else
		{
			ani = SIMON_ANI_JUMP_LEFT;
		}
	}
	else if (state == SIMON_STATE_SIT)
	{
		if (nx > 0)
		{
			ani = SIMON_ANI_SIT_RIGHT;
		}
		else
		{
			ani = SIMON_ANI_SIT_LEFT;
		}
	}
	else if (state == SIMON_STATE_SIT_FIGHT)
	{
		if (nx > 0)
		{
			ani = SIMON_ANI_SIT_FIGHT_RIGHT;
		}
		else
		{
			ani = SIMON_ANI_SIT_FIGHT_LEFT;
		}
	}
	else if (vx == 0)
	{
		if (nx > 0)
		{
			ani = SIMON_ANI_IDLE_RIGHT;
		}
		else
		{
			ani = SIMON_ANI_IDLE_LEFT;
		}
	}
	else if (vx > 0)
	{
		ani = SIMON_ANI_WALKING_RIGHT;
	}
	else
	{
		ani = SIMON_ANI_WALKING_LEFT;
	}
	animations[ani]->Render(this->Getx(), this->Gety());
}

void Simon::SetState(int state)
{
	GameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	case SIMON_STATE_WALKING_LEFT:
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		break;
	case SIMON_STATE_JUMP:
		if (y == 100)
			vy = -SIMON_JUMP_SPEED_Y;

	case SIMON_STATE_IDLE:
		vx = 0;
		if (nx > 0)
		{
			state = SIMON_ANI_JUMP_RIGHT;
		}
		else
		{
			state = SIMON_ANI_JUMP_LEFT;
		}
		break;
	case SIMON_STATE_FIGHT:
		vx = 0;
		if(nx>0)
		{
			state = SIMON_ANI_FIGHT_RIGHT;
		}
		else
		{
			state = SIMON_ANI_FIGHT_LEFT;
		}
		break;
	case SIMON_STATE_SIT:
		vx = 0;
		if (nx > 0)
		{
			state = SIMON_ANI_SIT_RIGHT;
		}
		else
		{
			state = SIMON_ANI_SIT_LEFT;
		}
		break;
	case SIMON_STATE_SIT_FIGHT:
		vx = 0;
		if (nx > 0)
		{
			state = SIMON_ANI_SIT_FIGHT_RIGHT;
		}
		else
		{
			state = SIMON_ANI_SIT_FIGHT_LEFT;
		}
		break;
	}
}


