#include "TestCaseManager.h"

#include "PlayerTurbo.h"
#include "GeneralDraw.h"
#include "GameMaster.h"
#include <iostream>

using namespace std;

void TestCaseManager::testAll()
{
	testPlayerTurboClass();
	testGeneralDrawClass();
	testGameMasterClass();

	//USE GENERAL DRAW's FUNCTION TO CLEAR SCREEN AFTER TEST
	GeneralDraw::ClearScreen();
}

//========================================

void TestCaseManager::testPlayerTurboClass()
{
	test_PT_drawPlayerTurbo();
	test_PT_drawPlayerTrail();
	test_PT_movePlayerTurbo();


}

void TestCaseManager::testGeneralDrawClass()
{
	test_GD_GoToXY();
	test_GD_DrawMapOutline();
	test_GD_ClearArena();
	test_GD_ClearScreen();
	test_GD_ClearRectangle();
	test_GD_DrawRectangle();
	test_GD_drawCurrentGameStats();
	test_GD_DrawTrailMeters();
	test_GD_DrawMeterBox();
}

void TestCaseManager::testGameMasterClass()
{
	test_GM_InitializeGame();
}

//========================================
//========================================

void TestCaseManager::test_PT_drawPlayerTurbo()
{
	PlayerTurbo test;
	test.DrawPlayerTurbo();
}

void TestCaseManager::test_PT_drawPlayerTrail()
{
	PlayerTurbo test;
	test.DrawPlayerTrail();
}

void TestCaseManager::test_PT_movePlayerTurbo()
{
	PlayerTurbo test;
	test.movePlayerTurbo();
}

//========================================
//========================================

void TestCaseManager::test_GD_GoToXY()
{
	GeneralDraw::GoToXY(-2, -2);
	GeneralDraw::GoToXY(5, 5);
	GeneralDraw::GoToXY(0, 0);
}

void TestCaseManager::test_GD_DrawMapOutline()
{
	GeneralDraw::DrawMapOutline();
}

void TestCaseManager::test_GD_ClearArena()
{
	GeneralDraw::ClearArena();
}

void TestCaseManager::test_GD_ClearScreen()
{
	GeneralDraw::ClearScreen();
}

void TestCaseManager::test_GD_ClearRectangle()
{
	GeneralDraw::ClearRectangle(-1, -1, -1, -1);
	GeneralDraw::ClearRectangle(0, 0, 5, 5);
}

void TestCaseManager::test_GD_DrawRectangle()
{
	GeneralDraw::DrawRectangle(-1, -1, -1, -1);
	GeneralDraw::DrawRectangle(0, 0, 5, 5);
}

void TestCaseManager::test_GD_drawCurrentGameStats()
{
	GeneralDraw::DrawCurrentGameStats(2, 1);
}

void TestCaseManager::test_GD_DrawTrailMeters()
{
	GeneralDraw::DrawTrailMeters(15, 15);
}

void TestCaseManager::test_GD_DrawMeterBox()
{
	GeneralDraw::DrawMeterBox();
}

//========================================
//========================================

void TestCaseManager::test_GM_InitializeGame()
{
	GameMaster test;
	test.InitializeGame();
}