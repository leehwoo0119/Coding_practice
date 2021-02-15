#pragma once
#include "Logic2D.h"
class LogicOthello : public Logic2D
{
private:
	virtual void analyzeGame(int, int, int, int);
	void Cal(int, int);
	
};

