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
	virtual void DrawBingo() = 0;
	virtual void DrawBingoTop() = 0;
	virtual string GetStone(int, int);
};

