#include "GameMaster.h"
#include "GameInfo.h"

GameMaster::GameMaster()
{
	InitializeGame();
}

void GameMaster::InitializeGame()
{
	//Set player values

	player_1.SetXCoord(GameInfo::startX_1);
	player_1.SetYCoord(GameInfo::startY_1);

	player_2.SetXCoord(GameInfo::startX_2);
	player_2.SetYCoord(GameInfo::startY_2);

	player_1.SetDirection(RIGHT);
	player_2.SetDirection(LEFT);

	player_1.SetPlayerColor(GameInfo::playerColour_1);
	player_2.SetPlayerColor(GameInfo::playerColour_2);

	player_1.SetPlayerUpgradeColor(GameInfo::upgradeColour_1);
	player_2.SetPlayerUpgradeColor(GameInfo::upgradeColour_2);

	player_1.SetTrailWidth(1);
	player_2.SetTrailWidth(1);

	//TEST STUFF JUST TO SEE DRAWING
	GeneralDraw::DrawMapOutline();
	player_1.drawPlayerTurbo();
	player_2.drawPlayerTurbo();

}