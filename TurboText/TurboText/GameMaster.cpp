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

	PlayGame();

}

void GameMaster::PlayGame()
{
	int p1wins = 0;
	int p2wins = 0;
	while (true)//rounds loop
	{
		if (p1wins >= 3)
		{
			break;
		}
		if (p2wins >= 3)
		{
			break;
		}

		processUserInputs();
		
		player_1.movePlayerTurbo();
		player_2.movePlayerTurbo();

		player_1.drawPlayerTurbo();
		player_2.drawPlayerTurbo();
		Sleep(1000/5);
	}
}

void GameMaster::processUserInputs()
{
	while (kbhit())
	{
		int key = _getch();
		switch (key)
		{
		case 119://w
		{
			player_1.SetDirection(UP);
			break;
		}
		case 97://a
		{
			player_1.SetDirection(LEFT);
			break;
		}
		case 115://s
		{
			player_1.SetDirection(DOWN);
			break;
		}
		case 100://d
		{
			player_1.SetDirection(RIGHT);
			break;
		}
		case 105://i
		{
			player_2.SetDirection(UP);
			break;
		}
		case 106://j
		{
			player_2.SetDirection(LEFT);
			break;
		}
		case 107://k
		{
			player_2.SetDirection(DOWN);
			break;
		}
		case 108://l
		{
			player_2.SetDirection(RIGHT);
			break;
		}
		default:
		{
			break;
		}
		}
	}
}
