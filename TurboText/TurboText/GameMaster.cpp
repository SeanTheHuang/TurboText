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

		player_2.SetDirection(p2Input(player_2.GetDirection()));

		player_1.SetDirection(p1Input(player_1.GetDirection()));
		player_1.SetDirection(p2Input(player_1.GetDirection()));
		
		player_1.movePlayerTurbo();
		player_2.movePlayerTurbo();

		player_1.drawPlayerTurbo();
		player_2.drawPlayerTurbo();
		Sleep(100);
	}
}

Direction GameMaster::p1Input(Direction _oldDir)
{
	if (kbhit() == true)
	{
		int key = _getch();
		switch (key)
		{
		case 119:
		{
			return UP;
			break;
		}
		case 97:
		{
			return LEFT;
			break;
		}
		case 115:
		{
			return DOWN;
			break;
		}
		case 100:
		{
			return RIGHT;
			break;
		}
		default:
		{
			return _oldDir;
			break;
		}
		}
	}
	else
	{
		return _oldDir;
	}
}

Direction GameMaster::p2Input(Direction _oldDir)
{
	if (kbhit() == true)
	{
		int key = _getch();
		switch (key)
		{
		case 105:
		{
			return UP;
			break;
		}
		case 106:
		{
			return LEFT;
			break;
		}
		case 107:
		{
			return DOWN;
			break;
		}
		case 108:
		{
			return RIGHT;
			break;
		}
		default:
		{
			return _oldDir;
			break;
		}
		}
	}
	else
	{
		return _oldDir;
	}
}