#include "Simon.h"
#include <algorithm>
#include"Game.h"

void Simon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	GameObject::Update(dt);
	vy += SIMON_GRAVITY*dt;
	/*vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;
	coEvents.clear();
	CalcPotentialCollisions(coObjects, coEvents);
	if (GetTickCount() - untouchable_start > SIMON_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = 0;
	}
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;
		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);
		if (nx != 0)
		{
			vx = 0;
		}
		if (ny != 0) 
		{
			vy = 0;
		}
	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++)
	{
		delete coEvents[i];
	}*/
	if (y > 100)

	{

		vy = 0;
		y = 100.0f;

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
		break;
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

void Simon::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
    top = y;
	right = x + SIMON_BBOX_WIDTH;
	left = y + SIMON_BBOX_HEIGHT;
}


