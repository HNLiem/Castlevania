#pragma once
#include "GameObject.h"


#define SIMON_WALKING_SPEED		0.15f
#define SIMON_JUMP_SPEED_Y		0.5f
#define SIMON_GRAVITY			0.07f

#define SIMON_STATE_IDLE			0
#define SIMON_STATE_WALKING_RIGHT	100
#define SIMON_STATE_WALKING_LEFT	200
#define SIMON_STATE_JUMP			300
#define SIMON_STATE_FIGHT			400
#define SIMON_STATE_JUMP_FIGHT		500
#define SIMON_STATE_SIT				600
#define SIMON_STATE_SIT_FIGHT		700


#define SIMON_ANI_IDLE_RIGHT		0
#define SIMON_ANI_IDLE_LEFT			1
#define SIMON_ANI_WALKING_RIGHT		2
#define SIMON_ANI_WALKING_LEFT		3
#define SIMON_ANI_FIGHT_RIGHT		4
#define SIMON_ANI_FIGHT_LEFT		5
#define SIMON_ANI_JUMP_RIGHT		6
#define SIMON_ANI_JUMP_LEFT			7
#define SIMON_ANI_SIT_RIGHT			8
#define SIMON_ANI_SIT_LEFT			9
#define SIMON_ANI_SIT_FIGHT_RIGHT	10
#define SIMON_ANI_SIT_FIGHT_LEFT	11
class Simon:public GameObject
{
public:
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};

