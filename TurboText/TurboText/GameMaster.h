#ifndef  _GAME_MASTER
#define  _GAME_MASTER

#include "PlayerTurbo.h"
#include "GeneralDraw.h"
#include "GameInfo.h"
#include <conio.h>

enum KEYS
{
	KUP = 0,
	KLEFT,
	KRIGHT,
	KDOWN,
	KENTER
};

class GameMaster
{
public:
	GameMaster();
	void InitializeGame();
	void PlayGame();
	void MainMenu();
	void QuitMenu();
	void HTPMenu();
	void CreditMenu();

private:
	//[Play Game] members
	PlayerTurbo player_1;
	PlayerTurbo player_2;

	char GameBoard[73][43];
	void processUserInputs();
	KEYS MenuInputs();
	
};

#endif