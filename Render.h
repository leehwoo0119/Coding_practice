#pragma once
#include <iostream>
using namespace std;

class Render
{
protected:
	int** dat = 0;
	int size = 0;
	bool isWide = 0;
	
	
	string stone[2] = { "¡Û", "¡Ü" };
	virtual string GetStone(int, int) = 0;
	
	
public:
	Render() {};
	~Render() {};

	//¿Àµ¨·Î->isWide=true  ¿À¸ñ->isWide=false
	void GetData(int**, int, bool);
	virtual void printBoard() = 0;

};

