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
	int turn = 2;
	bool isStone = false;
public:
	
	void MakeMemory(const int);				//메모리 할당
	void DeleteMemory(int);					//매모리 해제

	int** DatGetter() { return dat; };		//dat 반환
	int SizeGetter() { return size; };
	int SelectGameType();
	bool CheckCanStone(char*);
	void AlphaPosition(char*);

	//←→ 방향체크
	void CheckHorizantal(int, int, int, int, int);
	//↑↓ 방향체크
	void CheckVertical(int, int, int, int, int);
	//↘↖ 방향 체크
	void CheckRightDown(int, int, int, int, int);
	//↗↙ 방향체크
	void CheckRightUp(int, int, int, int, int);

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
	AlphaPosition(pos);
	char s1 = pos[0]; char s2 = pos[1]; // y  x
	isStone = false;
	if (dat[s1][s2] != 0) return false;
	dat[s1][s2] = turn;
	cout << dat[s1][s2] << " " << turn << endl;
	CheckHorizantal(s1, s2, turn, 0, 0);
	CheckVertical(s1, s2, turn, 0, 0);
	CheckRightDown(s1, s2, turn, 0, 0);
	CheckRightUp(s1, s2, turn, 0, 0);
	if (!isStone)
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
void Logic::CheckHorizantal(int y, int x, int turn, int cnt, int dir)
{
	//→ = (dir=1), ← = (dir=2)
	if (dir == 0)
	{
		if (x == 0)
			dir = 1;
		else if (dat[y][x - 1] == 0)
			dir = 1;
		else if (x == size - 1)
			dir = 2;
		else if (dat[y][x + 1] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (x == size)return;
	if (dir == 2)
		if (x == -1)return;
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		cout << "check1" << endl;
		if (dir == 1)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y][x - i] = turn;
		}
		if (dir == 2)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y][x + i] = turn;
		}
		isStone = true;
	}

	if (dir == 1)
		CheckHorizantal(y, x + 1, turn, cnt, dir);
	if (dir == 2)
		CheckHorizantal(y, x - 1, turn, cnt, dir);
}
void Logic::CheckVertical(int y, int x, int turn, int cnt, int dir)
{
	//↑ = (dir=1), ↓ = (dir=2)
	if (dir == 0)
	{
		if (y == size - 1)
			dir = 1;
		else if (dat[y + 1][x] == 0)
			dir = 1;
		else if (y == 0)
			dir = 2;
		else if (dat[y - 1][x] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (y == -1)return;
	if (dir == 2)
		if (y == size)return;
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		cout << "check2" << endl;
		if (dir == 1)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y + i][x] = turn;
		}
		if (dir == 2)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y - i][x] = turn;
		}
		isStone = true;
	}
	if (dir == 1)
		CheckVertical(y - 1, x, turn, cnt, dir);
	if (dir == 2)
		CheckVertical(y + 1, x, turn, cnt, dir);
}
void Logic::CheckRightDown(int y, int x, int turn, int cnt, int dir)
{
	//↘ = (dir=1), ↖ = (dir=2)
	if (dir == 0)
	{
		if (x == 0 || y == 0)
			dir = 1;
		else if (dat[y - 1][x - 1] == 0)
			dir = 1;
		else if (x == size - 1 || y == size - 1)
			dir = 2;
		else if (dat[y + 1][x + 1] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (y == size || x == size)return;
	if (dir == 2)
		if (y == -1 || x == -1)return;

	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		cout << "check3" << endl;
		if (dir == 1)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y - i][x - i] = turn;
		}
		if (dir == 2)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y + i][x + i] = turn;
		}
		//isStone = true;
	}
	if (dir == 1)
		CheckRightDown(y + 1, x + 1, turn, cnt, dir);
	if (dir == 2)
		CheckRightDown(y - 1, x - 1, turn, cnt, dir);
}
void Logic::CheckRightUp(int y, int x, int turn, int cnt, int dir)
{
	//↙ = (dir=1), ↗ = (dir=2)
	if (dir == 0)
	{
		if (x == size - 1 || y == 0)
			dir = 1;
		else if (dat[y - 1][x + 1] == 0)
			dir = 1;
		else if (x == 0 || y == size - 1)
			dir = 2;
		else if (dat[y + 1][x - 1] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (y == size || x == -1)return;
	if (dir == 2)
		if (y == -1 || x == size)return;

	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		cout << "check4" << endl;
		if (dir == 1)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y - i][x + i] = turn;
		}
		if (dir == 2)
		{
			for (int i = 0; i <= cnt; i++)
				dat[y + i][x - i] = turn;
		}
		isStone = true;
	}
	if (dir == 1)
		CheckRightUp(y + 1, x - 1, turn, cnt, dir);
	if (dir == 2)
		CheckRightUp(y - 1, x + 1, turn, cnt, dir);
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
	int j = 0;
	if (type == OMOK) j = 1;
	for ( j; j <= size ; j++)
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