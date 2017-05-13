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
	
	for (int i = 0; i < 44; i++)
	{
		GoToXY(xOffset(), yOffset() + i);
		for (int j = 0; j < 74;j++)
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

int GeneralDraw::getArenaWidth() { return arenaWidth; }

int GeneralDraw::getArenaHeight() { return arenaHeight; }