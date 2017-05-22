#ifndef  _GAME_INFO
#define  _GAME_INFO


#include "GeneralDraw.h"
#include <string>

class GameInfo
{
public:
	static const ECOLOUR playerColour_1 = col_red_black;
	static const ECOLOUR playerColour_2 = col_green_black;

	static const ECOLOUR upgradeColour_1 = col_yellow_black;
	static const ECOLOUR upgradeColour_2 = col_blue_black;

	static const ECOLOUR trailColour_1 = col_black_red;
	static const ECOLOUR trailColour_2 = col_black_green;

	static const int playerInitSpeed = 1;

	static const int startX_1 = 7;
	static const int startY_1 = 23;

	static const int startX_2 = 65;
	static const int startY_2 = 23;

	static const int startTrailOff = 20;

	static const int arenaWidth = 73;
	static const int arenaHeight = 43;

	static const std::string sCredits;
};


#endif