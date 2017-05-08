#ifndef  _GENERAL_DRAW
#define  _GENERAL_DRAW

#include <Windows.h>
#include <iostream>

class GeneralDraw
{
public:
	static enum ECOLOUR
	{
		col_white_black = 0,
		col_red_black = 1,
		col_green_black = 2,
		col_yellow_black = 3,
		col_blue_black = 4,
		col_magenta_black = 5,
		col_cyan_black = 6,
		col_black_grey = 7,
		col_black_white = 8
	};

	static void GoToXY(int _iX, int _iY);//goes to character coordinate on console
	static void DrawMapOutline();
	static void SetDrawColour(ECOLOUR _colour);

	static void ClearArena();//clears in the white box
	static void ClearScreen();//clears entire screen to black

	static void ClearRectangle(int _iX, int _iY, int _iWidth, int _iHeight); //clears a rectangular space
	static void DrawRectangle(int _iX, int _iY, int _iWidth, int _iHeight); //draws a rectangle with corners

	static int GetXOffset();
	static int GetYOffset();

private:
	const int iXOffset = 2;
	const int iYOffset = 3;
};

#endif