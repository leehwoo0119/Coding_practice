#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<int, int> m;

bool cmd(const pair<int, int>& p1, const pair<int, int>& p2)
{
    return p1.second > p2.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    string curNum = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != '{' && s[i] != '}' && s[i] != ',')
        {
            curNum += s[i];
            if (s[i + 1] != ',' && s[i + 1] != '}')
            {
                continue;
            }
            m[stoi(curNum)]++;
        }

        curNum = "";
    }

    vector<pair<int, int>> vv(m.begin(), m.end());

    sort(vv.begin(), vv.end(), cmd);
    for (auto x : vv)
    {
        answer.push_back(x.first);
    }
    return answer;
}