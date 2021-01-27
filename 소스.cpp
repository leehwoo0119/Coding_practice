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
	
	void MakeMemory(); //메모리 할당
	void DeleteMemory(); //매모리 해제

	int** DatGetter() { return dat; };//dat 반환
	int TurnGetter() { return turn; };
	int TurnCal(int);	

	void GetPos(char*, int);

	void CheckHorizantal(int);
	void CheckVertical(int);
	void CheckRightDown(int, int);
	void CheckRightUp(int, int);
};

struct Render {
private:
	int** dat = 0;
public:
	
	void GetDat(int**); //Logic의 dat 받아오기

	void DrawBoard(); //보드 그리기
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
	char s1 = 0, s2 = 0;
	

	for (int i = 0; i < 2; i++)
	{
		s1 = c[0]; s2 = c[1];
	}

	if (dat[s1 - '0'][s2 - '0'] == 0)
	{
		if (t == 1)
			dat[s1 - '0'][s2 - '0'] = 1;
		else if (t == 2)
			dat[s1 - '0'][s2 - '0'] = 2;
	}
	else
	{
		if (t == 1)turn = 2;
		if (t == 2)turn = 1;
	}
}

void Logic::CheckHorizantal(int i)
{
	int save[8] = { 0, };
	int save_Front = 0;
	int save_Behind = 0;
	for (int j = 0; j < SIZE; j++)
	{
		if (dat[i][j] != 0 && (dat[i][j] != dat[i][j + 1]) && (dat[i][j + 1] != 0))
		{
			save_Front = j;
			break;
		}			
		if (j == SIZE - 1)return;
	}
	for (int k = 0; k < SIZE - save_Front; k++)
	{
		save[k] = dat[i][save_Front + k];
	}
	for (int t = 0; t < SIZE - save_Front; t++)
	{
		if (save[t] == save[0] && t != 0)
			save_Behind = t + save_Front;
	}
	//cout << save[0] << ' ' << turn << endl;
	if (save[0] == 0 || save[0] != turn)return;
	for (int q = save_Front; q <= save_Behind; q++)
	{
		dat[i][q] = save[0];
	}
}
void Logic::CheckVertical(int i)
{
	int save[8] = { 0, };
	int save_Front = 0;
	int save_Behind = 0;
	for (int j = 0; j < SIZE; j++)
	{
		if (dat[j][i] != 0 && (dat[j][i] != dat[j+1][i]) && (dat[j + 1][i] != 0))
		{
			save_Front = j;
			break;
		}
		if (i == SIZE - 1)return;
	}
	for (int k = 0; k < SIZE - save_Front; k++)
	{
		save[k] = dat[save_Front + k][i];
	}
	for (int t = 0; t < SIZE - save_Front; t++)
	{
		if (save[t] == save[0] && t != 0)
			save_Behind = t + save_Front;		
	}
	if (save[0] == 0 || save[0] != turn)return;
	for (int q = save_Front; q <= save_Behind; q++)
	{
		dat[q][i] = save[0];
	}
}

void Logic::CheckRightDown(int y, int x)
{
	while (1)
	{
		y--; x--;
		if (y == 0 || x == 0)
		{
			break;
		}		
	}
	int ii = 0;
	int jj = 0;
	int save[8] = { 0, };
	int save_Front[2] = { 0, };
	int save_Behind[2] = { 0, };

	if (y == 0) jj = x; 
	else ii = y; 
	for (; ii < SIZE; jj++,ii++)
	{
		cout << ii << ' ' << jj << endl;
		if (dat[ii][jj] != 0 && (dat[ii][jj] != dat[ii + 1][jj + 1]) && (dat[ii + 1][jj + 1] != 0))
		{
			
			save_Front[0] = ii; save_Front[1] = jj;
			break;
		}
		if (jj == SIZE - 1)return;
	}
	for (int k = 0; k < SIZE - save_Front[1]; k++)
	{
		save[k] = dat[save_Front[0] + k][save_Front[1] + k];
	}
	for (int t = 0; t < SIZE - save_Front[1]; t++)
	{
		if (save[t] == save[0] && t != 0)
		{
			save_Behind[0] = t + save_Front[0];
			save_Behind[1] = t + save_Front[1];
		}
			
	}
	//cout << save_Front[0] << ' ' << save_Front[1] << ' '<< save_Behind[0] << save_Behind[1] << endl;
	//cout << save[0] << ' ' << turn << endl;
	if (save[0] == 0 || save[0] != turn)return;
	for (int q = save_Front[0], p = save_Front[1]; p <= save_Front[1]; q++, p++)
	{
		dat[q][p] = save[0];
	}
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
	//int i = 0;
	//int k = 0;

	Logic logic;
	Render render;
	char pos[3] = { 0, };
	logic.MakeMemory();

	render.GetDat(logic.DatGetter());

	while (1)
	{
		//system("cls");
		render.DrawBoard();
		logic.TurnCal(logic.TurnGetter());
		//cout << logic.TurnGetter()<<endl;
		cout << "Input Position: ";
		cin >> pos;
		logic.GetPos(pos, logic.TurnGetter());
		
		logic.CheckHorizantal(pos[0]-'0');
		logic.CheckVertical(pos[1]-'0');
		logic.CheckRightDown(pos[0] - '0', pos[1] - '0');
	}
	logic.DeleteMemory();
}

