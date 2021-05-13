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

    int check_1 = N - 1;

    while (check_1>0)
    {
        if (v[check_1 - 1] > v[check_1])break;
        check_1--;
    }
    //마지막 순열
    if (check_1 == 0)
    {
        cout << "-1";
        return 0;
    }

    sort(v.begin() + (check_1), v.end(),greater<>());
   
    int saveI = 0;
    for (int i = check_1; i < N; i++)
    {
        if (v[i] < v[check_1 - 1])
        {
            saveI = i;
            break;
        }
    }
     cout << check_1 << ' ' << saveI<<endl;
   
   
    swap(*(v.begin() + (check_1 - 1)), *(v.begin() + (saveI)));
    for (int i = 0; i < N; i++)
    {
        cout << v[i] <<' ';
    }
    return 0;
}



