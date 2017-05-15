#ifndef  _PLAYER_TURBO
#define  _PLAYER_TURBO

#include "GeneralDraw.h"

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

	void SetYCoord(int _i);

	void SetDirection(Direction _dDir);

	Direction GetDirection();

	void SetPlayerColor(ECOLOUR _cCol);

	void SetTrailColor(ECOLOUR _cCol);

	void SetPlayerUpgradeColor(ECOLOUR _cCol);

	void movePlayerTurbo();

	void drawPlayerTurbo();

private:
	int iSpeed;
	int iTrailWidth;
	bool bCanTouchOwnTail;
	int iPlayerXCoord;
	int iPlayerYCoord;

	Direction dDirection;
	ECOLOUR cPlayerColor;
	ECOLOUR cTrailColor;
	ECOLOUR cPlayerWithUpgradeColor;

	char getPlayerSymbol();
};

#endif