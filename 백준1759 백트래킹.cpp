#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C = 0;
vector<int>v;
vector<int>answer;
int moum = 0;

void CheckMoum(char _checkChar)
{
	if (_checkChar == 'a' || _checkChar == 'e' ||
		_checkChar == 'i' || _checkChar == 'o' ||
		_checkChar == 'u')
	{
		moum++;
	}
}

void Solve(int cnt)
{
	if (answer.size() == L)
	{
		string s;
		moum = 0;
		for (int i = 0; i < L; i++)
		{
			char c = answer[i] + 'a';
			s += c;
			CheckMoum(c);
		}
		if (moum != 0 && L - moum >= 2)
		{
			cout << s;
			cout << "\n";
		}		
	}
	for (int i = cnt; i < C; i++)
	{
		answer.push_back(v[i]);
		Solve(i + 1);
		answer.pop_back();
	}
}

int main() 
{
	cin >> L >> C;

	for (int i = 0; i < C; i++)
	{
		char input;
		cin >> input;
		v.push_back(input - 'a');
	}
	sort(v.begin(), v.end());
	Solve(0);
}