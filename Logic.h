#pragma once
#include <iostream>
using namespace std;

class Logic {
protected:
	int** dat = 0;
	int size = 0;
	int Size = 0;
	int gamemode = 0;
	int turn = 1;
public:
	Logic() {};
	~Logic();

	void MakeMemory();
	int** GetDat() { return dat; };
	int GetSize() { return size; };
	int GetMode() { return gamemode; };

	void SetMode(int value) { gamemode = value; };
	virtual bool inputData(string) = 0;
private:
	virtual void GameTypeMemoryMake() = 0;
	
};