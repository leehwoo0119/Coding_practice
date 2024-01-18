#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    int idx;

    // 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (idx = 0; idx < 26; idx++) {
        char alh = 'A' + idx;
        string tmp(1, alh);
        dic.insert({ tmp, idx + 1 });
    }

    int msg_len = msg.length();
    string w = "";
    // 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
    for (int i = 0; i < msg_len; i++) {
        std::cout << w << "\n";

        if (dic.count(w + msg[i]) == 0) {
            // 3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
            answer.push_back(dic[w]);

            // 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
            dic.insert({ w + msg[i], ++idx });
            w = msg[i];
        }
        else {
            w += msg[i];
        }

        if (i == msg_len - 1) {
            answer.push_back(dic[w]);
        }
    }

    return answer;
}


void main()
{
    solution("KAKAO");
}