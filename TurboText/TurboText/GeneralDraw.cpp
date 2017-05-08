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
	char a = 186;//vertical lines
	char b = 205;//horizontal lines

	//choose colour here
	SetDrawColour(col_white_black);

	GoToXY(3, 1);
	for (int i = 0; i < 74; i++)
	{
		std::cout << b;
	}
	GoToXY(2, 2);
	for (int i = 0; i < 45; i++)
	{
		GoToXY(2, 2 + i);
		std::cout << a;
	}
	GoToXY(87, 2);
	for (int i = 0; i < 45; i++)
	{
		GoToXY(77, 2+i);
		std::cout << a;
	}
	GoToXY(3, 46);
	for (int i = 0; i < 74; i++)
	{
		std::cout << b;
	}

	GoToXY(2, 1);
	a = 201;
	std::cout << a;

	a = 187;
	GoToXY(77, 1);
	std::cout << a;

	a = 200;
	GoToXY(2, 46);
	std::cout << a;

	a = 188;
	GoToXY(77, 46);
	std::cout << a;
}

void GeneralDraw::GoToXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

int GeneralDraw::GetXOffset()
{
	return 3;
}

int GeneralDraw::GetYOffset()
{
	return 2;
}

void GeneralDraw::ClearArena()      
{
	SetDrawColour(col_white_black);
	
	for (int i = 0; i < 44; i++)
	{
		GoToXY(GetXOffset(), GetYOffset() + i);
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