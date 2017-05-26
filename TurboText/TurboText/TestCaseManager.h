#ifndef  _TEST_CASE_MANAGER
#define  _TEST_CASE_MANAGER


//	Class tests functionality of the game.
//	The main reason to run testAll() is to
//	see if any functions cause an error.

//Note: - getters/setters functions are not tested.
//		- this is a very broad test, high chance of missing bugs.

class TestCaseManager
{
public:
	static void testAll();
private:
	TestCaseManager();
	TestCaseManager(const TestCaseManager&);

	static void testPlayerTurboClass();
	static void testGeneralDrawClass();
	static void testGameMasterClass();

	//Test call for functions

	//==PlayerTurbo (PT) class
	static void test_PT_drawPlayerTurbo();
	static void test_PT_drawPlayerTrail();
	static void test_PT_movePlayerTurbo();

	//==GeneralDraw (GD) class
	static void test_GD_GoToXY();
	static void test_GD_DrawMapOutline();
	static void test_GD_ClearArena();
	static void test_GD_ClearScreen();
	static void test_GD_ClearRectangle();
	static void test_GD_DrawRectangle();
	static void test_GD_drawCurrentGameStats();
	static void test_GD_DrawTrailMeters();
	static void test_GD_DrawMeterBox();

	//==GameMaster (GM) class
	static void test_GM_InitializeGame();
};

#endif 

