#include "Weapon.h"
#include"Game.h"
#include"GameObject.h"
#include<algorithm>


void Weapon::Update(DWORD dt,Simon *simon)
{
	GameObject::Update(dt);
	SetPosition(simon);
	


}

void Weapon::Render(Simon *simon)
{
	int ani;
	if (state == WEAPON_STATE_FIGHT)
	{
		if (simon->Getnx() > 0)
		{
			ani = WEAPON_ANI_FIGHT_LEVEL_A_RIGHT;
		}
		else
		{
			ani = WEAPON_ANI_FIGHT_LEVEL_A_LEFT;
		}
		animations[ani]->Render(x, y);
	}
	
}

void Weapon::SetState(int state,Simon *simon)
{
	GameObject::SetState(state);
	switch (state)
	{
	case WEAPON_STATE_FIGHT:
			
			if (simon->Getnx() > 0)
			{
				state = WEAPON_ANI_FIGHT_LEVEL_A_RIGHT;
			}
			else
			{
				state = WEAPON_ANI_FIGHT_LEVEL_A_LEFT;
			}
	}
	
}

void Weapon::SetPosition(Simon * simon)
{
	this->x = simon->Getx();
	this->y = simon->Gety();
}



