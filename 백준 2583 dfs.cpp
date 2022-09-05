#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int M, N, K;
int cnt;
int arr[101][101];
bool visited[101][101];
vector<int> res;

void dfs(int x, int y) {
    int nx, ny;

    visited[x][y] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < M && ny < N && !visited[nx][ny]) 
        {
            dfs(nx, ny);
        }
    }
}

int main(void) {

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) 
        {
            for (int k = x1; k < x2; k++)
            {
                arr[j][k] = 1;
                visited[j][k] = true;
            }
        }
    }
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            if (arr[i][j] == 0 && visited[i][j] == false)
            {
                cnt = 0;
                dfs(i, j);
                res.push_back(cnt);
            }
        }
    }
    sort(res.begin(), res.end());

    cout << res.size() << " ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";

    return 0;
}

































































































































































































































































































































































