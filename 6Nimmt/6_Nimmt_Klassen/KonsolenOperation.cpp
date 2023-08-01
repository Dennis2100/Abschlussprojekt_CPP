#include "pch.h"
#include "KonsolenOperation.h"

void SetCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { x, y };
	SetConsoleCursorPosition(hOut, coord);
}

void SetTextColor(int col)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	FlushConsoleInputBuffer(hOut);
	SetConsoleTextAttribute(hOut, col);
}
