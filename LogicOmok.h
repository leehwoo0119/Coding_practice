#pragma once
#include "Logic2D.h"
class LogicOmok : public Logic2D
{
private:
	void analyzeOmok(int, int, int);
	bool isStone = false;
	int omokCnt = 0;
};

