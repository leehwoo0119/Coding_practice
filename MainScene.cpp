#include "Logic.h"
#include "Logic2D.h"
#include "LogicOmok.h"
#include "Render.h"
#include "RenderNarrow.h"
#include "RenderWide.h"
int main()
{	
	cout << "���� ����" << endl;
	cout << "(1)���� (2)������" << endl;
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