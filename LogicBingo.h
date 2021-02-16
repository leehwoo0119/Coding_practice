#pragma once
#include "Logic2D.h"
class LogicBingo : public Logic2D
{
private:
	virtual void analyzeGame(int, int, int, int);
	virtual void GameTypeMemoryMake();
	void MemSet();
	int cnt = 0;
	int player = 1;
	int bingoNum = 0;
	int numArr[25] = { 0, };
};

