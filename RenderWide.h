#pragma once
#include "Render.h"

class RenderWide : public Render
{
private:
	int Size = 0;
	string line[11] = {
	"��","�� ",
	"����","������","���� ",
	"����","������","���� ",
	"����","������","���� ",
	};
	void printUITop();
	void printBoard();
	void DrawHorz(int, int, int, int, int);
	virtual void DrawBingo(int, int) = 0;
	virtual void DrawBingoTop() = 0;
	virtual string GetStone(int, int);
};

