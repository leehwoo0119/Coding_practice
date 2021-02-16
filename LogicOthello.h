#pragma once
#include "Logic2D.h"
class LogicOthello : public Logic2D
{
private:
	virtual void analyzeGame(int, int, int, int);
	virtual void GameTypeMemoryMake();
	void Cal(int, int);
	
};

