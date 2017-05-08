#ifndef  _PLAYER_TURBO
#define  _PLAYER_TURBO

enum Color
{
	RED = 0,
	PINK = 1,
	ORANGE = 2,
	BLUE = 4,
	TEAL = 5,
	GREEN = 6
};

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
	void SetSpeed(int _i);
	int GetSpeed();

	void SetTrailWidth(int _i);
	int GetTrailWidth();

	void SetTailTouch(bool _b);
	bool GetTailTouch();

	void SetXCoord(int _i);

	void SetYCoord(int _i);

	void SetDirection(Direction _dDir);

	void SetPlayerColor(Color _cCol);

	void SetTrailColor(Color _cCol);

	void SetPlayerUpgradeColor(Color _cCol);

private:
	int iSpeed = 1;
	int iTrailWidth;
	bool bCanTouchOwnTail;
	int iPlayerXCoord;
	int iPlayerYCoord;

	Direction dDirection;
	Color cPlayerColor;
	Color cTrailColor;
	Color cPlayerWithUpgradeColor;


};

#endif