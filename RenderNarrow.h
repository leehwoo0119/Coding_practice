#pragma once
#include "Render.h"
class RenderNarrow : public Render
{
private:
	string line[11] = {
	"��","�� ",
	"�� ","�� ","��",
	"�� ","�� ","��",
	"�� ","�� ","��",
	};

	void printUITop();
	void printBoard();
	void DrawHorz(int, int, int, int, int);
	
};

