#pragma once
#include "Render.h"

class RenderWide : public Render
{
private:
	string line[11] = {
	"式","弛 ",
	"忙式","式成式","式忖",
	"戍式","式托式","式扣",
	"戌式","式扛式","式戎",
	};
	int bingoNum = 1;
	void printUITop();
	void printBoard();
	void DrawHorz(int, int, int, int, int);
	void DrawBingo(int, int);
	virtual string GetStone(int, int);
};

