#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M = 0;
int r, c, d = 0;
int map[51][51];
int check[51][51];

//�������
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int Solve()
{
	//û�ұ� ����
	bool bPower = true;
	int cnt = 0;

	while (bPower)
	{	
		//û�� �����ϸ� û��
		if (!check[r][c] && map[r][c] == 0)
		{
			cnt++;
			check[r][c] = true;
		}	
		//���� ����ġ
		bool bBackSwitch = false;
		//4���� û�� �ǽ�
		for (int dirCnt = 0; dirCnt < 4; dirCnt++)
		{
			d = d - 1;
			if (d == -1)d = 3;

			int next_y = r + dy[d];
			int next_x = c + dx[d];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M)
			{
				if (!check[next_y][next_x] && map[next_y][next_x] == 0)
				{
					r = next_y;
					c = next_x;
					break;
				}
			}
			if (dirCnt == 3)bBackSwitch = true;
		}

		if (bBackSwitch)
		{
			int next_y = r - dy[d];
			int next_x = c - dx[d];

			if (next_y >= 0 && next_y < N &&
				next_x >= 0 && next_x < M &&
				map[next_y][next_x] == 0)
			{
				r = next_y;
				c = next_x;
			}
			else
			{
				bPower = false;
			}
		}
	}
	return cnt;
}

int main() 
{
	cin >> N >> M;

	cin >> r >> c >> d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}		
	}
	
	cout<< Solve();

}