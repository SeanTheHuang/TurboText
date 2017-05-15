#ifndef  _GAME_MASTER
#define  _GAME_MASTER

#include "PlayerTurbo.h"
#include "GeneralDraw.h"
#include <conio.h>
class GameMaster
{
public:
	GameMaster();
	void InitializeGame();
	void PlayGame();

private:
	//[Play Game] members
	PlayerTurbo player_1;
	PlayerTurbo player_2;

	char GameBoard[73][43];
	Direction p1Input(Direction _oldDir);
	Direction p2Input(Direction _oldDir);
};

#endif