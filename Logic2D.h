#pragma once
#include "Logic.h"
class Logic2D : public Logic
{
private:
	bool setData(int, int);
protected:
	virtual void analyzeGame(int, int, int) = 0;
	bool isStone = false;
	int othelloCnt = 0;
	int omokCnt = 0;
public:	
	bool inputData(string);
};

enum dir
{
	RIGHT = 0,
	LEFT,
	UP,
	DOWN,
	DR,
	UL,
	DL,
	UR
};
