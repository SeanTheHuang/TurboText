#include "GameMaster.h"
#include <string>

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	ShowConsoleCursor(false);
	GameMaster client;
	client.MainMenu();

	//Checking how many columns being drawn
	//
	//==== CONFIRMING PLAY ARENA - 43 IN HEIGHT ====
	/*for (int i = 1; i <= 43; i++)
	{
		GeneralDraw::GoToXY(2, i);
		std::cout << i;
	}

	//Checking how many rows being drawn
	//
	//==== CONFIRMING PLAY ARENA - 73 IN WIDTH ====
	/*GeneralDraw::GoToXY(2, 1);
	for (int i = 1; i <= 73; i++) {
		std::cout << '1';
	}*/

	int hang;
	std::cin >> hang;

	return 0;
}