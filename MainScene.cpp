#include "Logic.h"
#include "Logic2D.h"
#include "LogicOmok.h"
#include "LogicOthello.h"
#include "LogicBingo.h"
#include "Render.h"
#include "RenderNarrow.h"
#include "RenderBingo.h"
int main()
{	
	srand((unsigned)time(NULL));
	cout << "게임 고르기" << endl;
	cout << "(1)오목 (2)오델로 (3)빙고" << endl;
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
	else if (gamemode == 2)
	{
		l = new LogicOthello();
		r = new RenderBingo();
	}
	else
	{
		l = new LogicBingo();
		r = new RenderBingo();
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
		if(gamemode != 3)cout << "Input Position: ";		
		else cout << "Input Number: ";
		cin >> input;
		bGameover = l->inputData(input);
	}
	
	delete l;
	delete r;
	return 0;
}