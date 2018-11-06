#pragma once
#include "GameObject.h"
#include "Simon.h"
#define WEAPON_STATE_FIGHT 0
#define WEAPON_STATE_IDLE 1
#define WEAPON_ANI_FIGHT_LEVEL_A_RIGHT   12
#define WEAPON_ANI_FIGHT_LEVEL_A_LEFT	 13


class Weapon:public GameObject
{
private:
	int level;

public:
	Weapon() :GameObject()
	{
		
	}
	virtual void Update(DWORD dt,Simon *simon);
	virtual void Render(Simon *simon);
	void SetState(int state,Simon *simon);
	void SetLevel(int l=1) { this->level = l; }
	void SetPosition(Simon *simon);
	
};

