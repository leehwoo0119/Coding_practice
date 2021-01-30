#include <iostream>

#define SIZE_OMOK_BOARD 16
#define SIZE_OTHELLO_BOARD 8


using namespace std;

enum GameType
{
	OMOK = 0,
	OTHELLO = 9
};
struct Logic {
private:
	int** dat = 0;
	int size = 0;
	int turn = 1;
public:
	
	void MakeMemory(const int);				//메모리 할당
	void DeleteMemory(int);					//매모리 해제

	int** DatGetter() { return dat; };		//dat 반환
	int SizeGetter() { return size; };
	int SelectGameType();
	bool CheckCanStone(char*);

	//int TurnGetter() { return turn; };		//turn 반환

};

struct Render {
private:
	int** dat = 0;
	int size = 0;
	string line[20] = {
		"─","│ ",
		"┌"," ┬"," ┐",
		"├"," ┼"," ┤",
		"└"," ┴"," ┘",
		"┌─","─┬─","─┐",
		"├─","─┼─","─┤",
		"└─","─┴─","─┘",
	};
	string stone[2] = { "○", "●" };
public:
	
	void GetDatSize(int** p, int s) { dat = p; size = s; };		//Logic의 dat 받아오기

	void DrawBoard();						//보드 그리기
	void DrawHorz(int, int, int, int, int, int);
	string GetStone(int, int);
};

void Logic::MakeMemory(const int type)
{
	if (dat == NULL)
	{
		dat = (int**)new int* [size];

		for (int i = 0; i < size; i++)
		{
			dat[i] = (int*)new int[size];
			memset(dat[i], 0, sizeof(int) * size);
		}
		if (size == SIZE_OTHELLO_BOARD)
		{
			//초기 바둑알
			dat[3][3] = 2, dat[4][4] = 2;
			dat[3][4] = 1, dat[4][3] = 1;
		}		
	}
}
void Logic::DeleteMemory(int type)
{
	if (dat != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] dat[i];
		}
		delete[] dat;
	}
}

int Logic::SelectGameType()
{
	int type = 0;
	cout << "1. 오목 2. 오델로"<<endl;
	cin >> type;
	if (type == 1)size = SIZE_OMOK_BOARD;				//오목
	else if (type == 2)size = SIZE_OTHELLO_BOARD;		//오델로
	return type;
}
bool Logic::CheckCanStone(char* pos)
{
	char s1 = pos[0] - '0'; char s2 = pos[1] - '0'; // y  x

	if (dat[s1][s2] != 0) return false;

	dat[s1][s2] = turn + 1;

	turn = 1 - turn;

	return false;
}


void Render::DrawBoard()
{
	int type = 0;

	//오목 = type 0, 오델로 type = 9
	if (size == SIZE_OTHELLO_BOARD)type = OTHELLO;

	if (type == OTHELLO)
		cout << "   0   1   2   3   4   5   6   7" << endl;
	else if (type == OMOK)
		cout << "0 1 2 3 4 5 6 7 8 9 a b c d e f" << endl;

	DrawHorz(2 + type, 3 + type, 4 + type, 0 , 0, type);
	int i = 0;
	for(i = 0;i < size;i++)
	{
		if (type == OMOK && i == size - 2)
			break;
		if (type == OTHELLO)
		DrawHorz(1, 1, 1, 1, i, type);
		if (i == size - 1)break;
		DrawHorz(5 + type, 6 + type, 7 + type, 0, i + 1, type);
	}
	DrawHorz(8 + type, 9 + type, 10 + type, 0, i + 1, type);
}
void Render::DrawHorz(int L, int M, int R, int S, int i, int type)
{
	cout << line[L];
	for (int j = 0; j < size ; j++)
	{
		if (type == OTHELLO)
		{
			if (S == 0)cout << line[S];
			else  cout << GetStone(i, j);  
			if (j == size - 1)break;
			cout << line[M];
		}	
		
		else if (type == OMOK)
		{
			if (j == size - 2)break;
			if(dat[i][j]!=0)
				cout << GetStone(i, j);
			//else
				cout << line[M];
		}
		
	} 
	cout << line[R];
	
	if (type == OTHELLO)
	{
		if (S != 0)cout << i;
	}
	else if (type == OMOK)
	{
		if (i < 10)
			cout << ' ' << i;
		else
			cout << ' ' << (char)((char)i + 'a' - 10);
	}
	cout << endl;
}
string Render::GetStone(int y, int x)
{ 
	string res = "  ";
	if (dat[y][x] != 0)res = stone[dat[y][x] - 1];
	return res;
}
int main()
{
	int type = 0;
	char pos[2] = { 0, };
	Logic logic;
	Render render;

	
	type = logic.SelectGameType();
	logic.MakeMemory(type);
	render.GetDatSize(logic.DatGetter(),logic.SizeGetter());
	
	/*for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			cout << logic.dat[i][j];
		cout << endl;
	}*/
	while (1)
	{
		render.DrawBoard();
		cout << "Input Position: ";
		cin >> pos;
		logic.CheckCanStone(pos);
		
	}
	logic.DeleteMemory(type);
}