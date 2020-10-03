#pragma once

#include "resource.h"

//***************************************************************************************
// BlindfateApp.h
//(C) Robert Ruzbacky 2020 All Rights Reserved
//
//***************************************************************************************


// game states - tells you what status the game is at
#define GAME_STATE_INIT			0
#define GAME_STATE_SPLASHSCREEN	1
#define GAME_STATE_MENU			2
#define GAME_STATE_START		3
#define GAME_STATE_PAUSED		4
#define GAME_STATE_RUN			5
#define GAME_STATE_SHUTDOWN		6
#define GAME_STATE_EXIT			7

// game levels in order of progression
#define GAME_STATE_LEVEL1		8	// starting scene - alleyway
#define GAME_STATE_LEVEL2		9	// cafe
#define GAME_STATE_LEVEL3		10	// club
#define GAME_STATE_CAPTURED		11	// captured
#define GAME_STATE_LEVEL4		12	// arcade
#define GAME_STATE_LEVEL5		13	// park bench
#define GAME_STATE_LEVEL6		14	// dream
#define GAME_STATE_LEVEL7		15	// car
#define GAME_STATE_LEVEL8		16	// SWO house

