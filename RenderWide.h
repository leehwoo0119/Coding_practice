#pragma once
#include "Render.h"

class RenderWide : public Render
{
private:
	string line[11] = {
	"��","�� ",
	"����","������","����",
	"����","������","����",
	"����","������","����",
	};
	int bingoNum = 1;
	void printUITop();
	void printBoard();
	void DrawHorz(int, int, int, int, int);
	void DrawBingo(int, int);
	virtual string GetStone(int, int);
};

