#include "GeneralDraw.h"

void GeneralDraw::SetDrawColour(ECOLOUR _colour)   
{
	switch (_colour)
	{
	case col_white_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
	case col_red_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	}
	case col_green_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	}
	case col_yellow_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	}
	case col_blue_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	}
	case col_magenta_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	}
	case col_cyan_black:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
	case col_black_grey:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);
		break;
	}
	case col_black_white:
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
		break;
	}
	case col_black_red:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED);
		break;
	}
	case col_black_green:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_GREEN);
		break;
	}
	default:
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		break;
	}
	}
}


void GeneralDraw::DrawMapOutline()
{
	char a = 186;//vertical lines ascii
	char b = 205;//horizontal lines ascii

	//choose colour here
	SetDrawColour(col_white_black);

	//Draw TOP LINE
	GoToXY(arenaStartX+1, arenaStartY);
	for (int i = 0; i < arenaStartX + arenaWidth - 2; i++)
	{
		std::cout << b;
	}

	//Draw LEFT LINE
	for (int i = 0; i < arenaStartY + arenaHeight - 2; i++)
	{
		GoToXY(arenaStartX, arenaStartY + 1 + i);
		std::cout << a;
	}

	//Draw RIGHT LINE
	for (int i = 0; i < arenaStartY + arenaHeight - 2; i++)
	{
		GoToXY(arenaStartX+arenaWidth-1, arenaStartY+1+i);
		std::cout << a;
	}

	//Draw BOTTOM LINE
	GoToXY(arenaStartX+1, arenaStartY+arenaHeight-1);
	for (int i = 0; i < arenaStartX + arenaWidth - 2; i++)
	{
		std::cout << b;
	}

	//TOP-LEFT CORNER
	GoToXY(arenaStartX, arenaStartY);
	a = 201;
	std::cout << a;

	//TOP-RIGHT
	a = 187;
	GoToXY(arenaStartX + arenaWidth-1, arenaStartY);
	std::cout << a;

	//BOTTOM-LEFT
	a = 200;
	GoToXY(arenaStartX, arenaStartY+arenaHeight-1);
	std::cout << a;

	//BOTTOM-RIGHT
	a = 188;
	GoToXY(arenaStartX+arenaWidth-1, arenaStartY+arenaHeight-1);
	std::cout << a;
}

void GeneralDraw::GoToXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int GeneralDraw::xOffset()
{
	return iMapXOffset;
}

int GeneralDraw::yOffset()
{
	return iMapYOffset;
}

void GeneralDraw::ClearArena()      
{
	SetDrawColour(col_white_black);
	
	for (int i = 0; i < 43; i++)
	{
		GoToXY(xOffset(), yOffset() + i);
		for (int j = 0; j < 73;j++)
		{
			std::cout << " ";
		}
	}
}

void GeneralDraw::ClearScreen()
{
	SetDrawColour(col_white_black);

	for (int i = 0; i < 60; i++)
	{
		GoToXY(0, i);
		for (int j = 0;j < 80;j++)
		{
			std::cout << " ";
		}
	}
	GoToXY(0, 0);
}

void GeneralDraw::ClearRectangle(int _iX, int _iY, int _iWidth, int _iHeight)
{
	if ((_iX > 80) || (_iWidth > 80))
	{
		return;
	}
	GoToXY(_iX, _iY);

	for (int i = 0; i < _iHeight+1; i++)
	{
		GoToXY(_iX, _iY + i);
		for (int j = 0; j < _iWidth+1; j++)
		{
			std::cout << " ";
		}
	}
}

void GeneralDraw::DrawRectangle(int _iX, int _iY, int _iWidth, int _iHeight)
{
	if ((_iX > 80) || (_iWidth > 80))
	{
		return;
	}
	GoToXY(_iX, _iY);
	char a = 205;

	for (int i = 0; i < _iWidth; i++)
	{
		std::cout << a;
	}

	GoToXY(_iX, _iY + _iHeight);
	for (int i = 0; i < _iWidth; i++)
	{
		std::cout << a;
	}

	a = 186;

	GoToXY(_iX, _iY + 1);
	for (int i = 0; i < _iHeight; i++)
	{
		GoToXY(_iX, _iY + 1 + i);
		std::cout << a;
	}

	GoToXY(_iX + _iWidth, _iY + 1);
	for (int i = 0; i < _iHeight; i++)
	{
		GoToXY(_iX + _iWidth, _iY + 1+i);
		std::cout << a;
	}

	a = 201;
	GoToXY(_iX, _iY);
	std::cout << a;

	a = 187;
	GoToXY(_iX + _iWidth, _iY);
	std::cout << a;

	a = 200;
	GoToXY(_iX, _iY + _iHeight);
	std::cout << a;

	a = 188;
	GoToXY(_iX + _iWidth, _iY + _iHeight);
	std::cout << a;
}

int GeneralDraw::GetArenaWidth() { return arenaWidth; }

int GeneralDraw::GetArenaHeight() { return arenaHeight; }

int GeneralDraw::statsOffsetX() { return drawStatsX; }

int GeneralDraw::statsOffsetY() { return drawStatsY; }

void GeneralDraw::DrawCurrentGameStats(int player1wins, int player2wins)
{
	SetDrawColour(col_red_black);
	GoToXY(drawStatsX, drawStatsY);
	std::cout << "Player 1 wins: " << player1wins;

	SetDrawColour(col_green_black);
	GoToXY(drawStatsX + 51, drawStatsY);
	std::cout << "Player 2 wins: " << player2wins;


}

void GeneralDraw::DrawMeterBox()
{
	SetDrawColour(col_white_black);
	char a = 179;
	for (int i = 0; i < 4;i++)
	{
		GoToXY(4, 50 - i);
		std::cout << a;
		GoToXY(72, 50 - i);
		std::cout << a;

		GoToXY(51, 50 - i);
		std::cout << a;

		GoToXY(25, 50 - i);
		std::cout << a;
	}
	GoToXY(21, 47);
	std::cout << a;
	GoToXY(55, 47);
	std::cout << a;
	GoToXY(21, 48);
	std::cout << a;
	GoToXY(55, 48);
	std::cout << a;

	a = 195;
	GoToXY(4, 49);
	std::cout << a;
	GoToXY(51, 49);
	std::cout << a;

	a = 192;
	GoToXY(4, 51);
	std::cout << a;
	GoToXY(51, 51);
	std::cout << a;

	a = 217;
	GoToXY(25, 51);
	std::cout << a;
	GoToXY(72, 51);
	std::cout << a;

	a = 180;
	GoToXY(25, 49);
	std::cout << a;
	a = 180;
	GoToXY(72, 49);
	std::cout << a;

	a = 218;
	GoToXY(4, 46);
	std::cout << a;
	GoToXY(51, 46);
	std::cout << a;

	a = 191;
	GoToXY(25, 46);
	std::cout << a;
	GoToXY(72, 46);
	std::cout << a;

	a = 196;
	for (int i = 0; i < 20;i++)
	{
		GoToXY(5 + i, 49);
		std::cout << a;
		GoToXY(52 + i, 49);
		std::cout << a;
		GoToXY(5 + i, 51);
		std::cout << a;
		GoToXY(52 + i, 51);
		std::cout << a;
		GoToXY(5 + i, 46);
		std::cout << a;
		GoToXY(52 + i, 46);
		std::cout << a;
	}

	GoToXY(7, 49);
	std::cout << "Trail";// Meter";
	GoToXY(65, 49);
	std::cout << "Trail";
	a = 193;
	GoToXY(55, 49);
	std::cout << a;
	GoToXY(21, 49);
	std::cout << a;
	a = 194;
	GoToXY(21, 46);
	std::cout << a;
	GoToXY(55, 46);
	std::cout << a;

	
	a = 196;
	for (int i = 0; i < 25;i++)
	{
		GoToXY(26+i, 46);
		std::cout << a;
		GoToXY(26 + i, 51);
		std::cout << a;
	}
	GeneralDraw::SetDrawColour(col_yellow_black);
	GoToXY(28, 46);
	std::cout << "TURBO TEXT";
	GoToXY(39, 51);
	std::cout << "TURBO TEXT";

	
}

void GeneralDraw::DrawTrailMeters(int p1trail, int p2trail)
{
	SetDrawColour(col_white_black);

	for (int i = 0; i < 20; i++)
	{
		GoToXY(5 + i, 50);
		std::cout << " ";
	}

	SetDrawColour(col_red_black);
	char c = 219;
	for (int j = 0; j < p1trail; j++)
	{
		GoToXY(5 + j, 50);
		std::cout << c;
	}

	
	SetDrawColour(col_white_black);
	for (int i = 0; i < 20; i++)
	{
		GoToXY(5 + 47 + i, 50);
		std::cout << " ";
	}
	

	
	SetDrawColour(col_green_black);
	for (int j = 0; j < p2trail; j++)
	{
		GoToXY(5 + 47 + j, 50);
		std::cout << c;
	}
}