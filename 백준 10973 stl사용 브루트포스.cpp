#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)

{
    int N = 0;
    vector<int> v;

    cin >> N;
  
    for (int i = 0; i < N; i++)
    {
        int input = 0;
        cin >> input;
        v.push_back(input);
    }

    if (prev_permutation(v.begin(), v.end()))
    {
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it << ' ';
        }
    }
    else
        cout << "-1";
    return 0;
}



