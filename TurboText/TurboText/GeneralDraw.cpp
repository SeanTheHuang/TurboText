#include "GeneralDraw.h"

void GeneralDraw::DrawMapOutline()
{
	char a = 186;//vertical lines
	char b = 205;//horizontal lines

	//choose colour here
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

void GoToXY(int _iX, int _iY)
{
	COORD point;
	point.X = _iX;
	point.Y = _iY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}