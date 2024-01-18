#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dic;
    int idx;

    // 1. ���̰� 1�� ��� �ܾ �����ϵ��� ������ �ʱ�ȭ�Ѵ�.
    for (idx = 0; idx < 26; idx++) {
        char alh = 'A' + idx;
        string tmp(1, alh);
        dic.insert({ tmp, idx + 1 });
    }

    int msg_len = msg.length();
    string w = "";
    // 2. �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã�´�.
    for (int i = 0; i < msg_len; i++) {
        std::cout << w << "\n";

        if (dic.count(w + msg[i]) == 0) {
            // 3. w�� �ش��ϴ� ������ ���� ��ȣ�� ����ϰ�, �Է¿��� w�� �����Ѵ�.
            answer.push_back(dic[w]);

            // 4. �Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ�(c), w+c�� �ش��ϴ� �ܾ ������ ����Ѵ�.
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