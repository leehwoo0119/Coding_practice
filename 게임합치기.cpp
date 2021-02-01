
#include <iostream>
#define SIZE_OMOK_BOARD 16
#define SIZE_OTHELLO_BOARD 8
using namespace std;

struct Logic {
private:
	int** dat = 0;
	int type = 0;
	int size = 0;
	int turn = 2;
	int othelloCnt = 0;
	int omokCnt = 0;
	bool isStone = false;

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
public:

	void MakeMemory(const int); //메모리 할당
	void DeleteMemory(); //매모리 해제

	int** DatGetter() { return dat; }; //dat 반환
	int SizeGetter() { return size; };
	void ResetOmokCnt() { omokCnt = 0; };
	int SelectGameType();
	bool CheckCanStone(char*);
	void AlphaPosition(char*);

	//방향체크
	void Check(int, int, int, int);

	void Cal(int, int);
	bool WinCheck();
};

struct Render {
private:
	int** dat = 0;
	int size = 0;
	string line[20] = {
	"─","│ ",
	"┌ ","┬ ","┐",
	"├ ","┼ ","┤",
	"└ ","┴ ","┘",
	"┌─","─┬─","─┐",
	"├─","─┼─","─┤",
	"└─","─┴─","─┘",
	};
	string stone[2] = { "○", "●" };

	enum GameType
	{
		OMOK = 0,
		OTHELLO = 9
	};
public:

	void GetDatSize(int** p, int s) { dat = p; size = s; }; //Logic의 dat 받아오기

	void DrawBoard(); //보드 그리기
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
		if (type == 2)//오델로
		{
			//초기 바둑알
			dat[3][3] = 2, dat[4][4] = 2;
			dat[3][4] = 1, dat[4][3] = 1;
		}
	}
}
void Logic::DeleteMemory()
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
	cout << "1. 오목 2. 오델로" << endl;
	cin >> type;
	if (type == 1)size = SIZE_OMOK_BOARD; //오목
	else if (type == 2)size = SIZE_OTHELLO_BOARD; //오델로
	return type;
}
bool Logic::CheckCanStone(char* pos)
{
	AlphaPosition(pos);
	char s1 = pos[0]; char s2 = pos[1]; // y  x
	isStone = false;
	if (dat[s1][s2] != 0) return false;
	dat[s1][s2] = turn;

	for (int i = 0; i < 8; i++)
	{
		Check(s1, s2, turn, i);
		othelloCnt = 0;
	}
				
	if (type == 2 && !isStone)
	{
		dat[s1][s2] = 0;
		return false;
	}
	if (turn == 1)turn = 2;
	else if (turn == 2)turn = 1;
	return false;
}
void Logic::AlphaPosition(char* pos)
{
	for (int i = 0; i < 2; i++)
	{
		if (pos[i] >= '0' && pos[i] <= '9')
			pos[i] -= '0';
		else if (pos[i] >= 'a' && pos[i] <= 'f')
			pos[i] = pos[i] - 'a' + 10;
	}
}
void Logic::Check(int y, int x, int turn, int dir)
{	
	
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		othelloCnt++;

	switch (dir)
	{
	case RIGHT:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y, x - i);

		if (dat[y][x] == dat[y][x + 1])omokCnt++;
		Check(y, x + 1, turn, dir);
		break;
	case LEFT:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y, x + i);

		if (dat[y][x] == dat[y][x - 1])omokCnt++;
		Check(y, x - 1, turn, dir);
		break;
	case UP:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x);

		if (dat[y][x] == dat[y - 1][x])omokCnt++;
		Check(y - 1, x, turn, dir);
		break;
	case DOWN:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x);

		if (dat[y][x] == dat[y + 1][x])omokCnt++;
		Check(y + 1, x, turn, dir);
		break;
	case DR:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x - i);

		if (dat[y][x] == dat[y + 1][x + 1]) omokCnt++;
		Check(y + 1, x + 1, turn, dir);
		break;
	case UL:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x + i);

		if (dat[y][x] == dat[y - 1][x - 1]) omokCnt++;
		Check(y - 1, x - 1, turn, dir);
		break;
	case DL:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y - i, x + i);

		if (dat[y][x] == dat[y + 1][x - 1])omokCnt++;
		Check(y + 1, x - 1, turn, dir);
		break;
	case UR:
		if (dat[y][x] == turn && othelloCnt != 0)
			for (int i = 0; i <= othelloCnt; i++)
				Cal(y + i, x - i);

		if (dat[y][x] == dat[y - 1][x + 1])omokCnt++;
		Check(y - 1, x + 1, turn, dir);
		break;
	}


}
void Logic::Cal(int y, int x)
{
	dat[y][x] = turn;
	isStone = true;
}

bool Logic::WinCheck()
{
	//cout << omokCnt << "o" << endl;
	//오목
	if (type == 1)
	{
		if (omokCnt >= 4)
		{
			if (turn == 2)cout << "흑돌의 승리" << endl;
			else if (turn == 1)cout << "백돌의 승리" << endl;
			return true;
		}
	}
	ResetOmokCnt();
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

	DrawHorz(2 + type, 3 + type, 4 + type, 0, 0, type);
	int i = 0;
	for (i = 0; i < size; i++)
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
	int j = 0;
	if (type == OMOK) j = 1;
	for (j; j <= size; j++)
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
			if (j == size - 1)break;
			if (dat[i][j] != 0)
				cout << GetStone(i, j);
			else
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
	char pos[3] = { 0, };
	Logic logic;
	Render render;

	type = logic.SelectGameType();
	logic.MakeMemory(type);
	render.GetDatSize(logic.DatGetter(), logic.SizeGetter());

	while (1)
	{
		//system("cls");
		render.DrawBoard();
		cout << "Input Position: ";
		cin >> pos;
		logic.CheckCanStone(pos);
		if (logic.WinCheck()) break;
	}
	logic.DeleteMemory();
}
