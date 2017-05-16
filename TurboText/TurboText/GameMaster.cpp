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

	MainMenu();
	//PlayGame();

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

void GameMaster::MainMenu()
{
	GeneralDraw::DrawMapOutline();
	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(3, 3);
	std::cout << "            ______           __             ______          __         ";
	GeneralDraw::GoToXY(3, 4);
	std::cout << "           /_  __/_  _______/ /_  ____     /_  __/__  _  __/ /_        ";
	GeneralDraw::GoToXY(3, 5);
	std::cout << " ______     / / / / / / ___/ __ \\/ __ \\     / / / _ \\| |/_/ __/  ______";
	GeneralDraw::GoToXY(3, 6);
	std::cout << "/_____/    / / / /_/ / /  / /_/ / /_/ /    / / /  __/>  </ /_   /_____/";
	GeneralDraw::GoToXY(3, 7);
	std::cout << "          /_/  \\__,_/_/  /_.___/\\____/    /_/  \\___/_/|_|\\__/          ";

	int iMenuOption = 0;
	int iy = 24;
	int keyp1;
	int keyp2;
	bool gotime = false; 
	while (true)
	{
		switch (iMenuOption)
		{
		case 0:
			iy = 24;
			break;
		case 1:
			iy = 22;
			break;
		case 2:
			iy = 20;
			break;
		case 3:
			iy = 18;
			break;
		default:
			iy = iy;
		}
		
		for (int i = 0;i < 7; i++)
		{
			GeneralDraw::GoToXY(35, 18 + (2 * i));
			std::cout << "           ";
		}
		
		GeneralDraw::GoToXY(36, iy);
		if (iMenuOption == 0)
		{
			GeneralDraw::SetDrawColour(col_yellow_black);
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "PLAY GAME";
		GeneralDraw::GoToXY(35, iy + 2);
		if (iMenuOption == 1)
		{
			GeneralDraw::SetDrawColour(col_yellow_black);
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "HOW TO PLAY";
		GeneralDraw::GoToXY(37, iy + 4);
		if (iMenuOption == 2)
		{
			GeneralDraw::SetDrawColour(col_yellow_black);
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "CREDITS";
		GeneralDraw::GoToXY(38, iy + 6);
		if (iMenuOption == 3)
		{
			GeneralDraw::SetDrawColour(col_yellow_black);
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "QUIT";

		keyp1 = _getch();
		if (keyp1 == 13)
		{
			keyp2 = 13;
		}
		else
		{
			keyp2 = _getch();
		}

		switch (keyp2)
		{
		case 13://enter
		{
			gotime = true;
			break;
		}
		case 72: //up
		{
			if (iMenuOption != 0)
			{
				iMenuOption--;
			}
			break;
		}
		case 80://down
		{
			if (iMenuOption != 3)
			{
				iMenuOption++;
			}
			break;
		}
		default:
		{
			break;
		}
		}
		
	}




	

}