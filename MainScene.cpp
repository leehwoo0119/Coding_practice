#include "Logic.h"
#include "Logic2D.h"
#include "LogicOmok.h"
#include "LogicOthello.h"
#include "Render.h"
#include "RenderNarrow.h"
#include "RenderWide.h"
int main()
{	
	cout << "게임 고르기" << endl;
	cout << "(1)오목 (2)오델로" << endl;
	cout << "Input Gamemode: ";


	Logic* l = 0;
	Render* r = 0;
	int gamemode = 0;
	cin >> gamemode;
	
	if (gamemode == 1)
	{
		l = new LogicOmok();
		r = new RenderNarrow();
	}
	else 
	{
		l = new LogicOthello();
		r = new RenderWide();
	} 
	l->SetMode(gamemode);
	l->MakeMemory();
	r->GetData(l->GetDat(),l->GetSize(), l->GetMode() == 2);

	string input = "";
	bool bGameover = false;
	while (1)
	{		
		//system("cls");
		r->printBoard();
		if (bGameover)break;
		cout << "Input Position: ";
		cin >> input;
		bGameover = l->inputData(input);
	}
	
	return 0;
}