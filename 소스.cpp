#include <iostream>
#include <iomanip>

#define SIZE 8

using namespace std;
struct Logic {
private:
	int** dat = 0;
	int turn = 0;
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

	void Check(int, int);
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
		dat[3][3] = 1, dat[4][4] = 1;
		dat[3][4] = 2, dat[4][3] = 2;
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
	if (turn == 0)
	{
		turn = 1;
		return 0;
	}
	if (turn == 1)
	{
		turn = 0;
		return 1;
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
		if (t == 0)
			dat[s1 - '0'][s2 - '0'] = 1;
		else if (t == 1)
			dat[s1 - '0'][s2 - '0'] = 2;
	}
	else
	{
		if (t == 0)turn = 1;
		if (t == 1)turn = 0;
	}
}

void Logic::Check(int i, int j)
{
	if (j == SIZE) return;

	
	if (dat[i][j] == dat[save_front[0]][save_front[1]]&& dat[i][j]!=0&&i== save_front[0])
	{
		save_behind[0] = i; save_behind[1] = j;
		cout << save_front[0] << ' ' << save_front[1] << endl;
		cout << save_behind[0] << ' ' << save_behind[1] << endl;

		cout << save<<endl;
		for (int i = save_front[1]; i <= save_behind[1]; i++)dat[save_front[0]][i] = save;
	}
	if (dat[i][j] == 1)
	{
		if (dat[i][j] == dat[i][j + 1]) { /*cout << i << ' ' << j << endl;*/ return;}
		else if (dat[i][j + 1] == 0) {/* cout << i << ' ' << j << endl;*/ return; }
		else
		{
			save = 2;
			save_front[0] = i; save_front[1] = j;			
			Check(i, j+1);
		}
	}
	if (dat[i][j] == 2)
	{
		if (dat[i][j] == dat[i][j + 1]) { /*cout << i << ' ' << j << endl;*/ return;
		}
		else if (dat[i][j + 1] == 0) {/* cout << i << ' ' << j << endl;*/ return;
		}
		else
		{
			save = 1;
			save_front[0] = i; save_front[1] = j;
			Check(i, j + 1);
		}
	}
	
	Check(i, j+1);
	
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
	int i = 0;
	int j = 0;

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
		for(int i=0;i<SIZE;i++)
		logic.Check(i,j);
	}
	logic.DeleteMemory();
}

