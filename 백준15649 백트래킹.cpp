#include <iostream>

using namespace std;
#define MAX 9

int N, M;
int arr[MAX];
bool visited[MAX];

void Dfs(int _cnt)
{
    if (_cnt == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            arr[_cnt] = i;
            Dfs(_cnt + 1);
            visited[i] = false;
        }     
    }
}

int main() {
    cin >> N >> M;
    Dfs(0);
}
