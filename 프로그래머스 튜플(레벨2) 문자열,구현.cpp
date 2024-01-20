#include <string>
#include <vector>
#include <map>

using namespace std;

int idx = 0;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> m;

    //1.길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        idx++;
        string s = "";
        s += ch;
        m.insert({ s,idx });
    }

    string w = "";
    for (int i = 0; i < msg.length(); i++)
    {
        //사전에 없으면
        //2.사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        if (m.count(w + msg[i]) == 0)
        {
            answer.push_back(m[w]);

            //4.입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
            idx++;
            m.insert({ w + msg[i],idx });

            //3.w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
            w = msg[i];
        }
        //사전에 있으면
        else
        {
            w += msg[i];
        }

        if (i == msg.length() - 1)
        {
            answer.push_back(m[w]);
        }
    }
    return answer;
}


void main()
{
    solution("KAKAO");
}