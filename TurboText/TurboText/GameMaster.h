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

	//Gameboard characters
	// 'E' <= empty spot

	// 'A' <= player 1 Turbo
	// 'B' <= player 2 Turbo

	// '1' <= player 1 trail
	// '2' <= player 2 trail
	char GameBoard[GameInfo::arenaWidth][GameInfo::arenaHeight];

	//[Play Game] functions
	void GameUserInputs();
	void GameIntro(int);
	void cleanInputStack(); //Use so players don't stack commands before game

	void checkCollision(bool&, bool&); //Return: 0 = no collision, 1 = Player 1 hit, 2 = Player 2 hit
	int Gameloop(); //Return: 0 = no winner, 1 = player 1 won, 2 = player 2 won
	void GameEndScreen(int, int);

	//Menu Functions
	KEYS MenuInputs();
	
};

#endif