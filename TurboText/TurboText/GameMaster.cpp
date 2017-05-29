#include "GameMaster.h"
#include "GameInfo.h"

GameMaster::GameMaster()
{
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

	player_1.SetTrailColor(GameInfo::trailColour_1);
	player_2.SetTrailColor(GameInfo::trailColour_2);

	player_1.SetTrailOff(20/*GameInfo::startTrailOff*/);
	player_2.SetTrailOff(20/*ameInfo::startTrailOff*/);

	//Clean up board
	for (int i = 0; i < GameInfo::arenaWidth; i++) {
		for (int j = 0; j < GameInfo::arenaHeight; j++)
		{
			GameBoard[i][j] = 'E';
		}
	}
	
}

void GameMaster::PlayGame()
{
	int p1wins = 0;
	int p2wins = 0;
	int roundNum = 1;
	int roundWinner;
	int foundWinner = 0; // Cases: 1 = Player 1 has won, 2 = Player 2 has won

	while (foundWinner == 0)//rounds loop
	{
		InitializeGame();
		GeneralDraw::ClearArena();
		GeneralDraw::DrawMapOutline();
		GeneralDraw::DrawCurrentGameStats(p1wins, p2wins);
		GeneralDraw::DrawTrailMeters(player_1.GetTrailOff(), player_2.GetTrailOff());
		GeneralDraw::DrawMeterBox();
		player_1.SetbTrail(false);
		player_2.SetbTrail(false);
		player_1.DrawPlayerTurbo();
		player_2.DrawPlayerTurbo();

		GameIntro(roundNum);		//GAME INTRO
		CleanInputStack();
		roundWinner = Gameloop();	//MAIN GAMEPLAY LOOP HERE

		//Tell players outcome of last round, updats stats
		GeneralDraw::SetDrawColour(col_white_black);
		GeneralDraw::ClearRectangle(26, 14, 30, 4);
		GeneralDraw::DrawRectangle(26, 14, 30, 4);

		GeneralDraw::SetDrawColour(col_yellow_black);
		GeneralDraw::GoToXY(28, 15);
		std::cout << "Round " << roundNum << " winner: ";

		if (roundWinner == 1) {
			std::cout << "Player 1 !!";
			p1wins++;
		}
		else if (roundWinner == 2) {
			std::cout << "Player 2 !!";
			p2wins++;
		}
		else {
			std::cout << "Noone!!";
		}

		GeneralDraw::GoToXY(28, 17);
		std::cout << "[Press any key to continue]";

		//Determine if someone is winner
		if (p1wins >= 3)
		{
			foundWinner = 1;
		}
		if (p2wins >= 3)
		{
			foundWinner = -1;
		}
		else {
			roundNum++; //Count rounds if no winner yet
		}

		//Hang program until players want to continue
		int temp = _getch();
		if (temp == 0 || temp == 0xE0) {
			temp = _getch();
		}

		//Clean result box
		GeneralDraw::ClearRectangle(26, 14, 30, 4);
	}

	//End game stuff and clean up
	GeneralDraw::ClearRectangle(4, 46, 69, 7);

	GameEndScreen(p1wins, p2wins);
	MainMenu();
}

void GameMaster::GameIntro(int currentRound)
{
	//TODO randomise item here, inform user of item

	GeneralDraw::SetDrawColour(ECOLOUR::col_yellow_black);
	//GeneralDraw::DrawRectangle(30, 10, 16, 6);
	GeneralDraw::GoToXY(36, 15);
	std::cout << "Round: " << currentRound;
	GeneralDraw::GoToXY(28, 18);
	std::cout << "Press [Any key] to start";
	
	int temp = _getch();
	if (temp == 0 || temp == 0xE0) {
		temp = _getch();
	}

	GeneralDraw::ClearRectangle(28, 15, 25, 3);
	
	for (int i = 3; i >= 1; i--) {
		GeneralDraw::GoToXY(40, 15);
		std::cout << i;
		Sleep(1000);
	}

	GeneralDraw::GoToXY(39, 15);
	std::cout << "GO!";
	Sleep(500);
	GeneralDraw::GoToXY(39, 15);
	std::cout << "       ";

}

int GameMaster::Gameloop()
{
	bool playerAlive_1 = true, playerAlive_2 = true;
	int returnValue = 0;
	int p1oldx, p1oldy, p2oldx, p2oldy;
	while (playerAlive_1 && playerAlive_2) {
	
		//Inputs
		GameUserInputs();

		p1oldx = player_1.GetX() + GeneralDraw::xOffset();
		p1oldy = player_1.GetY() + GeneralDraw::yOffset();
		p2oldx = player_2.GetX() + GeneralDraw::xOffset();
		p2oldy = player_2.GetY() + GeneralDraw::yOffset();

		//Move - Updateboard as well
		if ((player_1.GetbTrail() == false) || (player_1.GetTrailOff() <= 0))
		{
			GameBoard[player_1.GetX()][player_1.GetY()] = '1';
		}
		
		if ((player_2.GetbTrail() == false) || (player_2.GetTrailOff() <= 0))
		{
			GameBoard[player_2.GetX()][player_2.GetY()] = '2';
		}

		
		

		//Draw playerTrail
		if ((player_1.GetbTrail() == false) || (player_1.GetTrailOff() <= 0))
		{
			player_1.DrawPlayerTrail();
			GeneralDraw::SetDrawColour(col_red_black);
			GeneralDraw::GoToXY(23, 47);
			std::cout << "Z";
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
			GeneralDraw::GoToXY(p1oldx, p1oldy);std::cout << " ";
			player_1.SetTrailOff(player_1.GetTrailOff() - 1);
			GeneralDraw::GoToXY(23, 47);
			std::cout << "Z";
		}

		if ((player_2.GetbTrail() == false) || (player_2.GetTrailOff() <= 0))
		{
			player_2.DrawPlayerTrail();
			GeneralDraw::SetDrawColour(col_green_black);
			GeneralDraw::GoToXY(53, 47);
			std::cout << "M";
		}
		else
		{
			GeneralDraw::SetDrawColour(col_white_black);
			GeneralDraw::GoToXY(p2oldx, p2oldy);std::cout << " ";
			player_2.SetTrailOff(player_2.GetTrailOff() - 1);
			GeneralDraw::GoToXY(53, 47);
			std::cout << "M";
		}

		GeneralDraw::DrawTrailMeters(player_1.GetTrailOff(), player_2.GetTrailOff());
		player_1.movePlayerTurbo();
		player_2.movePlayerTurbo();

		//Collision detection
		CheckCollision(playerAlive_1, playerAlive_2);

		//Resolve result of collision
		
		
		//Draw next frame
		player_1.DrawPlayerTurbo();
		player_2.DrawPlayerTurbo();
		Sleep(1000 / 10);
	}

	if (!playerAlive_1 && !playerAlive_2) {
		returnValue = 0;
	}
	else if (!playerAlive_1) {
		returnValue = 2;
	}
	else {
		returnValue = 1;
	}

	return returnValue;
}

void GameMaster::CheckCollision(bool& playerAlive_1, bool& playerAlive_2)
{
	//Check outside arena
	if (player_1.GetX() < 0 || player_1.GetX() >= GameInfo::arenaWidth
		|| player_1.GetY() < 0 || player_1.GetY() >= GameInfo::arenaHeight)
	{
		playerAlive_1 = false;
	}

	if (player_2.GetX() < 0 || player_2.GetX() >= GameInfo::arenaWidth
		|| player_2.GetY() < 0 || player_2.GetY() >= GameInfo::arenaHeight)
	{
		playerAlive_2 = false;
	}

	//100% Turbos are in arena

	//Check Turbo hit eachother
	if ((player_1.GetX() == player_2.GetX()) && (player_1.GetY() == player_2.GetY()))
	{
		playerAlive_1 = false;
		playerAlive_2 = false;
	}

	char currentPos;

	//Check hitting trails now
	currentPos = GameBoard[player_1.GetX()][player_1.GetY()];

	if (currentPos == '1' && !player_1.GetTailTouch()) {
		playerAlive_1 = false;
	}
	else if (currentPos == '2') {	//Touch enemy trail
		playerAlive_1 = false;
	}

	currentPos = GameBoard[player_2.GetX()][player_2.GetY()];

	if (currentPos == '2' && !player_2.GetTailTouch()) {
		playerAlive_2 = false;
	}
	else if (currentPos == '1') {	//Touch enemy trail
		playerAlive_2 = false;
	}


}

void GameMaster::GameEndScreen(int p1wins, int p2wins)
{
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::ClearRectangle(24, 15, 30, 10);
	GeneralDraw::DrawRectangle(24, 15, 30, 10);

	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(32, 16);
	std::cout << "[End Game Stats]";

	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::GoToXY(27, 18);
	std::cout << "Player 1: " << p1wins << " Wins";
	GeneralDraw::GoToXY(27, 20);
	std::cout << "Player 2: " << p2wins << " Wins";

	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(26, 24);
	std::cout << "Press any [key] to continue";

	int temp = _getch();

	if (temp == 0 || temp == 0xE0) {
		temp = _getch();
	}
}

void GameMaster::GameUserInputs()
{
	while (_kbhit())
	{
		int key = _getch();

		if (key == 0 || key == 0xE0) {
			key = _getch();
		}

		switch (key)
		{
		case 119://w
		{
			if (player_1.GetDirection() != DOWN)
				player_1.SetDirection(UP);
			break;
		}
		case 97://a
		{
			if (player_1.GetDirection() != RIGHT)
				player_1.SetDirection(LEFT);
			break;
		}
		case 115://s
		{
			if (player_1.GetDirection() != UP)
				player_1.SetDirection(DOWN);
			break;
		}
		case 100://d
		{
			if (player_1.GetDirection() != LEFT)
				player_1.SetDirection(RIGHT);
			break;
		}
		case 122://z
		{
			if (player_1.GetbTrail() == false)
			{
				player_1.SetbTrail(true);
			}
			else
			{
				player_1.SetbTrail(false);
			}
			break;
		}
		case 105://i
		{
			if (player_2.GetDirection() != DOWN)
				player_2.SetDirection(UP);
			break;
		}
		case 106://j
		{
			if (player_2.GetDirection() != RIGHT)
				player_2.SetDirection(LEFT);
			break;
		}
		case 107://k
		{
			if (player_2.GetDirection() != UP)
				player_2.SetDirection(DOWN);
			break;
		}
		case 108://l
		{
			if (player_2.GetDirection() != LEFT)
				player_2.SetDirection(RIGHT);
			break;
		}
		case 109://m
		{
			if (player_2.GetbTrail() == false)
			{
				player_2.SetbTrail(true);
			}
			else
			{
				player_2.SetbTrail(false);
			}
			break;
		}
		default:
		{
			break;
		}
		}
		break; // This fixes the bug.
	}
}

void GameMaster::MainMenu()
{
	GeneralDraw::ClearArena();

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
				PlayGame();
				break;
			}
			case 1:
			{
				HTPMenu();
				iMenuOption = 0;
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

void GameMaster::HTPMenu()
{
	bool leave = false;
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::ClearRectangle(6, 8, 64, 35);
	GeneralDraw::DrawRectangle(6, 8, 64, 35);

	GeneralDraw::GoToXY(32, 10);
	GeneralDraw::SetDrawColour(col_yellow_black);
	std::cout << "How To Play";

	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::GoToXY(14, 12);
	GeneralDraw::SetDrawColour(col_red_black); 
	std::cout << "Player 1's Controls:";
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::GoToXY(42, 13);
	std::cout << "[W] = UP";
	GeneralDraw::GoToXY(42, 14);
	std::cout << "[A] = LEFT";
	GeneralDraw::GoToXY(42, 15);
	std::cout << "[S] = DOWN";
	GeneralDraw::GoToXY(42, 16);
	std::cout << "[D] = RIGHT";
	GeneralDraw::GoToXY(42, 17);
	std::cout << "[Z] = TURN OFF TRAIL";
	GeneralDraw::GoToXY(14, 19);
	GeneralDraw::SetDrawColour(col_green_black); 
	std::cout << "Player 2's Controls:";
	GeneralDraw::SetDrawColour(col_white_black);
	GeneralDraw::GoToXY(42, 20);
	std::cout << "[I] = UP";
	GeneralDraw::GoToXY(42, 21);
	std::cout << "[J] = LEFT";
	GeneralDraw::GoToXY(42, 22);
	std::cout << "[K] = DOWN";
	GeneralDraw::GoToXY(42, 23);
	std::cout << "[L] = RIGHT";
	GeneralDraw::GoToXY(42, 24);
	std::cout << "[M] = TURN OFF TRAIL";
	GeneralDraw::GoToXY(14, 26);
	std::cout << "Avoid both your trail and your opponents trail.";
	GeneralDraw::GoToXY(14, 28);
	std::cout << "Win the round by forcing your opponent into a trail or";
	GeneralDraw::GoToXY(14, 29);
	std::cout << "wall.";
	GeneralDraw::GoToXY(14, 31);
	std::cout << "When a player runs into a trail or wall they lose the";
	GeneralDraw::GoToXY(14, 32);
	std::cout << "round.";
	GeneralDraw::GoToXY(14, 34);
	std::cout << "First player to win three rounds wins the game!";
	GeneralDraw::GoToXY(14, 36);
	std::cout << "Toggle your trail on and off off for a limited amount";
	GeneralDraw::GoToXY(14, 37);
	std::cout << "of time to give yourself oppertunities to escape!";

	GeneralDraw::SetDrawColour(col_yellow_black);
	GeneralDraw::GoToXY(28, 41);
	std::cout << "Press ENTER to return";
	while (MenuInputs() != KENTER)
	{

	}
	GeneralDraw::ClearRectangle(6, 8, 64, 35);
	return;
}

void GameMaster::CleanInputStack()
{
	while (_kbhit())
	{
		int temp = _getch();
		if (temp == 0 || temp == 0xE0) {
			temp = _getch();
		}
	}
}