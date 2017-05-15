#include "PlayerTurbo.h"

PlayerTurbo::PlayerTurbo(
	int startX, int startY, Direction startDir,
	ECOLOUR playerCol, ECOLOUR trailCol,
	ECOLOUR upgradedCol, int speed
)
{
	iPlayerXCoord = startX;
	iPlayerYCoord = startY;
	dDirection = startDir;

	cPlayerColor = playerCol;
	cTrailColor = trailCol;
	cPlayerWithUpgradeColor = upgradedCol;

	iSpeed = speed;
	iTrailWidth = 1;
	bCanTouchOwnTail = false;
}

PlayerTurbo::PlayerTurbo()
{
	iPlayerXCoord = 0;
	iPlayerYCoord = 0;
	dDirection = UP;

	cPlayerColor = col_white_black;
	cTrailColor = col_white_black;
	cPlayerWithUpgradeColor = col_white_black;

	iSpeed = 1;
	iTrailWidth = 1;
	bCanTouchOwnTail = false;
}

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

Direction PlayerTurbo::GetDirection()
{
	return dDirection;
}

void PlayerTurbo::SetPlayerColor(ECOLOUR _cCol)
{
	cPlayerColor = _cCol;
};

void PlayerTurbo::SetTrailColor(ECOLOUR _cCol)
{
	cTrailColor = _cCol;
};

void PlayerTurbo::SetPlayerUpgradeColor(ECOLOUR _cCol)
{
	cPlayerWithUpgradeColor = _cCol;
};

void PlayerTurbo::movePlayerTurbo()
{
	switch (dDirection)
	{
	case UP:
		iPlayerYCoord--;
		break;

	case DOWN:
		iPlayerYCoord++;
		break;

	case LEFT:
		iPlayerXCoord--;
		break;

	case RIGHT:
		iPlayerXCoord++;
		break;

	default:
		break;
	}
}

void PlayerTurbo::drawPlayerTurbo()
{
	int xPos = GeneralDraw::xOffset() + iPlayerXCoord;
	int yPos = GeneralDraw::yOffset() + iPlayerYCoord;

	char symbol = getPlayerSymbol();

	if (!bCanTouchOwnTail)
		GeneralDraw::SetDrawColour(cPlayerColor);
	else
		GeneralDraw::SetDrawColour(cPlayerWithUpgradeColor);

	GeneralDraw::GoToXY(xPos, yPos);
	std::cout << symbol;
}

char PlayerTurbo::getPlayerSymbol()
{
	switch (dDirection)
	{
	case UP:
		return '^';
		break;

	case DOWN:
		return 'v';
		break;

	case LEFT:
		return '<';
		break;

	case RIGHT:
		return '>';
		break;

	default:
		return '?';
		break;
	}
}

