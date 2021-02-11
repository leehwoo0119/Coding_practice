#include "Logic.h"
#include "Logic2D.h"
#include "LogicOmok.h"
#include "Render.h"
#include "RenderNarrow.h"
#include "RenderWide.h"
int main()
{	
	cout << "게임 고르기" << endl;
	cout << "(1)오목 (2)오델로" << endl;
	cout << "Input Gamemode: ";


	Logic* l = new LogicOmok();
	Render* r = 0;

	if (l->GetMode() == 1)r = new RenderNarrow();
	else r = new RenderWide();
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