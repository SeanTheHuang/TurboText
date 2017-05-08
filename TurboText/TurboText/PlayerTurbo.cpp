#include "PlayerTurbo.h"

void PlayerTurbo::SetSpeed(int _i)
{
	iSpeed = _i;
};
int PlayerTurbo::GetSpeed()
{
	return iSpeed;
};

void PlayerTurbo::SetTrailWidth(int _i)
{
	iTrailWidth = _i;
};
int PlayerTurbo::GetTrailWidth()
{
	return iTrailWidth;
};

void PlayerTurbo::SetTailTouch(bool _b)
{
	bCanTouchOwnTail = _b;
};
bool PlayerTurbo::GetTailTouch()
{
	return bCanTouchOwnTail;
};

void PlayerTurbo::SetXCoord(int _i)
{
	iPlayerXCoord = _i;
};

void PlayerTurbo::SetYCoord(int _i)
{
	iPlayerYCoord = _i;
};


void PlayerTurbo::SetDirection(Direction _dDir)
{
	dDirection = _dDir;
};

void PlayerTurbo::SetPlayerColor(Color _cCol)
{
	cPlayerColor = _cCol;
};

void PlayerTurbo::SetTrailColor(Color _cCol)
{
	cTrailColor = _cCol;
};

void PlayerTurbo::SetPlayerUpgradeColor(Color _cCol)
{
	cPlayerWithUpgradeColor = _cCol;
};