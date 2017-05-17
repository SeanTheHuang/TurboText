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
	int iLastMenuOption = 1;
	int iy = 24;
	bool confirm = false;

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

		if (iMenuOption != iLastMenuOption)
		{
			for (int i = 0; i < 7; i++)//draws black where menu items are
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
		}

		iLastMenuOption = iMenuOption;
		switch (MenuInputs())
		{
		case KUP:
		{
			if (iMenuOption != 0)
			{
				iMenuOption -= 1;
			}
			break;
		}
		case KDOWN:
		{
			if (iMenuOption != 3)
			{
				iMenuOption += 1;
			}
			break;
		}
		case KENTER:
		{
			confirm = true;
			break;
		}
		default:
		{
			break;
		}
		}

		if (confirm == true)
		{
			switch (iMenuOption)
			{
			case 0:
			{
				break;
			}
			case 1:
			{
				break;
			}
			case 2:
			{
				CreditMenu();
				iMenuOption = 0;
				break;
			}
			case 3:
			{
				QuitMenu();
				iMenuOption = 0;
				break;
			}
			default:
				break;
			}
			confirm = false;
			
			continue;
		}
	}
}

KEYS GameMaster::MenuInputs()
{
	while (true)
	{

		int keyp1 = _getch();
		if (keyp1 != 13 && keyp1 != 0xE0)
		{
			continue;
		}
		int keyp2;
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
			return KENTER;
			break;
		}
		case 72: //up
		{
			return KUP;
			break;
		}
		case 80://down
		{
			return KDOWN;
			break;
		}
		case 75:
		{
			return KLEFT;
			break;
		}
		case 77:
		{
			return KRIGHT;
			break;
		}
		default:
		{
			continue;
			break;
		}
		}
	}
}

void GameMaster::QuitMenu()
{
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::ClearRectangle(20, 14, 40, 20);
	GeneralDraw::DrawRectangle(20, 14, 40, 20);
	
	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(25, 20);
	std::cout << "Are you sure you want to quit?";
	bool confirm = false;
	int iMenuOption = 1;
	
	while (true)
	{
		GeneralDraw::GoToXY(34, 28);
		if (iMenuOption == 0)
		{
			GeneralDraw::SetDrawColour(col_red_black);
			if (confirm == true)
			{
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "QUIT   ";

		if (iMenuOption == 1)
		{
			GeneralDraw::SetDrawColour(col_green_black);
			if (confirm == true)
			{
				GeneralDraw::ClearRectangle(20, 14, 40, 20);
				return;
			}
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
		}
		std::cout << "RETURN";

		switch (MenuInputs())
		{
		case KLEFT:
		{
			if (iMenuOption == 0)
			{
				iMenuOption = 1;
			}
			else
			{
				iMenuOption = 0;
			}
			break;
		}
		case KRIGHT:
		{
			if (iMenuOption == 0)
			{
				iMenuOption = 1;
			}
			else
			{
				iMenuOption = 0;
			}
			break;
		}
		case KENTER:
		{
			confirm = true;
		}
		default:
		{
			//continue;
			break;
		}
		}
	}
}

void GameMaster::CreditMenu()
{
	bool leave = false;
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::ClearRectangle(6, 14, 64, 12);
	GeneralDraw::DrawRectangle(6, 14, 64, 12);

	GeneralDraw::GoToXY(36, 16);
	GeneralDraw::SetDrawColour(col_yellow_black);
	std::cout << "Credits";

	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::GoToXY(14, 20);
	std::cout << GameInfo::sCredits;

	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(28, 24);
	std::cout << "Press ENTER to return";
	while (MenuInputs() != KENTER)
	{

	}
	GeneralDraw::ClearRectangle(6, 14, 64, 12);
	return;
}