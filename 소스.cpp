#include <iostream>
#include <iomanip>

#define SIZE 8

using namespace std;
struct Logic {
private:
	int** dat = 0;
	int turn = 1;
	int save = 0;
	int save_front[2] = { 0, };
	int save_behind[2] = { 0, };
public:
	bool isStone = false;
	void MakeMemory();						//메모리 할당
	void DeleteMemory();					//매모리 해제

	int** DatGetter() { return dat; };		//dat 반환
	int TurnGetter() { return turn; };		//turn 반환
	int TurnCal(int);						//turn 계산

	void GetPos(char*, int);				//위치값에따른 dat값 계산

	void TurnReturn(char* , int);
	//←→ 방향체크
	void CheckHorizantal(int, int, int, int, int);
	//↑↓ 방향체크
	void CheckVertical(int, int, int, int, int);
	//↘↖ 방향 체크
	void CheckRightDown(int, int, int, int, int);
	//↗↙ 방향체크
	void CheckRightUp(int, int, int, int, int);

	bool CanStone(char*, int);

	int WinCheck(int);						//승리체크
};

struct Render {
private:
	int** dat = 0;
public:
	
	void GetDat(int**);						//Logic의 dat 받아오기

	void DrawBoard();						//보드 그리기
};

void Logic::MakeMemory()
{
	if (dat == NULL)
	{
		dat = (int**)new int* [SIZE];

		for (int i = 0; i < SIZE; i++)
		{
			dat[i] = (int*)new int[SIZE];
			memset(dat[i], 0, sizeof(int) * SIZE);
		}
		//초기 바둑알
		dat[3][3] = 2, dat[4][4] = 2;
		dat[3][4] = 1, dat[4][3] = 1;
	}
}
void Logic::DeleteMemory()
{
	if (dat != NULL)
	{
		for (int i = 0; i < SIZE; i++)
		{
			delete[] dat[i];
		}
		delete[] dat;
	}
}

int Logic::TurnCal(int t)
{
	if (turn == 1)
	{
		turn = 2;
		return 1;
	}
	if (turn == 2)
	{
		turn = 1;
		return 2;
	}
}

void Logic::GetPos(char* c, int t)
{

	if (dat[c[0] - '0'][c[1] - '0'] == 0)
	{
		if (t == 1)
			dat[c[0] - '0'][c[1] - '0'] = 1;
		else if (t == 2)
			dat[c[0] - '0'][c[1] - '0'] = 2;
	}
	else
	{
		TurnReturn(c, t);
	}
}
void Logic::TurnReturn(char* c, int t)
{

	if (t == 1)
	{
		//cout << "입력 위치가 잘못되었습니다." << endl;
		turn = 2;
	}
	if (t == 2)
	{
		//cout << "입력 위치가 잘못되었습니다." << endl;
		turn = 1;
	}
	if (!isStone)dat[c[0] - '0'][c[1] - '0'] = 0;

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
		else if (x == SIZE - 1)
			dir = 2;
		else if (dat[y][x + 1] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (x == SIZE)return;
	if (dir == 2)
		if (x == -1)return;
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;
	
	if (dat[y][x] == turn && cnt != 0)
	{
		//cout << "check1" << endl;
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
		if (y == SIZE - 1)
			dir = 1;
		else if (dat[y + 1][x] == 0)
			dir = 1;
		else if (y == 0)
			dir = 2;
		else if (dat[y - 1][x] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (y == -1)return ;
	if (dir == 2)
		if (y == SIZE)return ;
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		//cout << "check2" << endl;
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
void Logic::CheckRightDown(int y, int x, int turn, int cnt,int dir)
{
	//↘ = (dir=1), ↖ = (dir=2)
	if (dir == 0)
	{
		if(x == 0 || y == 0)
			dir = 1;
		else if (dat[y - 1][x - 1] == 0)
			dir = 1;
		else if(x == SIZE - 1 || y == SIZE - 1)
			dir = 2;
		else if (dat[y + 1][x + 1] == 0 )
			dir = 2;
	}
	if (dir == 1)
		if (y == SIZE || x == SIZE)return;
	if (dir == 2)
		if (y == -1 || x == -1)return;
		
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;
	
	if (dat[y][x] == turn && cnt != 0)
	{
		//cout << "check3" << endl;
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
		isStone = true;
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
		if (x == SIZE - 1 || y == 0)
			dir = 1;
		else if (dat[y - 1][x + 1] == 0)
			dir = 1;
		else if (x == 0 || y == SIZE - 1)
			dir = 2;
		else if (dat[y + 1][x - 1] == 0)
			dir = 2;
	}
	if (dir == 1)
		if (y == SIZE || x == -1)return;
	if (dir == 2)
		if (y == -1 || x == SIZE)return;
		
	if (dat[y][x] == 0) return;
	if (dat[y][x] != turn && dat[y][x] != 0)
		cnt++;

	if (dat[y][x] == turn && cnt != 0)
	{
		//cout << "check4" << endl;
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
bool Logic::CanStone(char* pos, int t)
{	
	bool res = false;
	
	if (isStone)res = true;
	if (!res)TurnReturn(pos, t);
	return res;
}
int Logic::WinCheck(int type)
{
	int whitePoint = 0; int blackPoint = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (dat[i][j] == 1)blackPoint++;
			else if (dat[i][j] == 2)whitePoint++;
		}
	}
	if (type == 0)
	{
		if (blackPoint == 0)
		{
			cout << "백돌승" << endl;
			return 1;
		}
		else if (whitePoint == 0)
		{
			cout << "흑돌승" << endl;
			return 1;
		}
	}
	if (type == 1)
	{
		if (blackPoint > whitePoint)cout << "흑돌승" << endl;
		else if (blackPoint < whitePoint)cout << "백돌승" << endl;
		else cout << "무승부" << endl;
		return 1;
	}
	return 0;
}
void Render::GetDat(int** p)
{
	dat = p;
}

void Render::DrawBoard()
{
	cout << "  0   1   2   3   4   5   6   7" << endl;

 
  //바둑판 맨위

    cout << "┌─ ";

    for (int i = 1; i < SIZE; i++)
    {
            cout << "─┬─ ";
    }
     cout << "─┐";
	 cout << endl;
    //바둑판 중앙

    for (int i = 1; i < SIZE*2; i++) {
		if (i % 2 == 0)
            cout << "├─ ";
		else
		{			
			
			if(dat[i/2][0] == 0)
				cout << "│   ";
			else if (dat[i/2][0] == 1)
				cout << "│ ○";
			else if(dat[i/2][0] == 2)
				cout << "│ ●";
		}
        for (int j = 1; j < SIZE; j++)
        {			
			if (i % 2 == 0)
				cout << "─┼─ ";
			else
			{
				if (dat[i/2][j] == 0)
					cout << "│   ";
				else if (dat[i/2][j] == 1)
					cout << "│ ○";
				else if (dat[i/2][j] == 2)
					cout << "│ ●";
			}
        }	
		if (i % 2 == 0)
			cout << "─┤";
		else cout << "│ " << i / 2;
	 cout << endl;
    }
	
    //바죽판 맨아래

    cout << "└─ ";

    for (int i = 1; i < SIZE; i++)
    {
        cout << "─┴─ ";
    }
    cout << "─┘";
	cout << endl;
}
int main()
{
	Logic logic;
	Render render;
	int isWin = 0;
	int cnt = 3;
	char pos[3] = { 0, };
	logic.MakeMemory();

	render.GetDat(logic.DatGetter());

	while (1)
	{
		logic.isStone = false;
		cnt++;
		cout << cnt << endl;
		//system("cls");
		render.DrawBoard();
		logic.TurnCal(logic.TurnGetter());
		cout << "Input Position: ";
		cin >> pos;
		logic.GetPos(pos, logic.TurnGetter());
		
		
		logic.CheckHorizantal(pos[0] - '0', pos[1]-'0', logic.TurnGetter(), 0, 0);
		logic.CheckVertical(pos[0] - '0', pos[1] - '0', logic.TurnGetter(), 0, 0);
		logic.CheckRightDown(pos[0] - '0', pos[1] - '0', logic.TurnGetter(), 0, 0);
		logic.CheckRightUp(pos[0] - '0', pos[1] - '0', logic.TurnGetter(), 0, 0);
		logic.CanStone(pos, logic.TurnGetter());
		isWin = logic.WinCheck(0);		
		if(cnt==64)logic.WinCheck(1);
		if (isWin == 1)break;
	}
	logic.DeleteMemory();
}

