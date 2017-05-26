#include "GameMaster.h"
#include "TestCaseManager.h"

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
	//Run test here. REMOVE IF WANT TO RUN 0.015 seconds faster! (and the weird preloads)
	TestCaseManager::testAll();

	ShowConsoleCursor(false);
	GameMaster client;
	client.MainMenu();

	int hang;
	std::cin >> hang;

	return 0;
}