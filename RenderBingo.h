#pragma once
#include "RenderWide.h"

class RenderBingo : public RenderWide
{
private:

	int bingoNum = 0;
	int numArr[25] = { 0, };
	int cnt = 0;
	virtual void DrawBingo(int, int);
	virtual void DrawBingoTop();
};


