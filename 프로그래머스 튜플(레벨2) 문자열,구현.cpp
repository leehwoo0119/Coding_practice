#include <string>
#include <vector>
#include <map>

using namespace std;

int idx = 0;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> m;

    //1.���̰� 1�� ��� �ܾ �����ϵ��� ������ �ʱ�ȭ�Ѵ�.
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
        //������ ������
        //2.�������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã�´�.
        if (m.count(w + msg[i]) == 0)
        {
            answer.push_back(m[w]);

            //4.�Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ�(c), w+c�� �ش��ϴ� �ܾ ������ ����Ѵ�.
            idx++;
            m.insert({ w + msg[i],idx });

            //3.w�� �ش��ϴ� ������ ���� ��ȣ�� ����ϰ�, �Է¿��� w�� �����Ѵ�.
            w = msg[i];
        }
        //������ ������
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