#ifndef  _PLAYER_TURBO
#define  _PLAYER_TURBO

#include "GeneralDraw.h"
#include "GameInfo.h"

enum Direction
{
	UP = 0,
	RIGHT = 1,
	DOWN = 2,
	LEFT = 3,
};

class PlayerTurbo
{
public:
	PlayerTurbo(
		int startX, int startY, Direction startDir,
		ECOLOUR playerCol, ECOLOUR trailCol,
		ECOLOUR upgradedCol, int speed
	);

	PlayerTurbo();

	void SetSpeed(int _i);
	int GetSpeed();

	void SetTrailWidth(int _i);
	int GetTrailWidth();

	void SetTailTouch(bool _b);
	bool GetTailTouch();

	void SetXCoord(int _i);
	int GetX();

	void SetYCoord(int _i);
	int GetY();

	void SetDirection(Direction _dDir);

	Direction GetDirection();

	void SetTrailOff(int _i);
	int GetTrailOff();

	void SetPlayerColor(ECOLOUR _cCol);

	void SetTrailColor(ECOLOUR _cCol);

	void SetPlayerUpgradeColor(ECOLOUR _cCol);

	bool GetbTrail();
	void SetbTrail(bool _b);

	void movePlayerTurbo();

	void DrawPlayerTurbo();
	void DrawPlayerTrail();

private:
	int iSpeed;
	int iTrailWidth;
	bool bCanTouchOwnTail;
	int iPlayerXCoord;
	int iPlayerYCoord;
	int iTrailOff;
	bool bTrail = false;

	Direction dDirection;
	ECOLOUR cPlayerColor;
	ECOLOUR cTrailColor;
	ECOLOUR cPlayerWithUpgradeColor;

	char GetPlayerSymbol();
};

#endif