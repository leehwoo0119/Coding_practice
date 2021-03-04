#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct INFO
{
	string name_;
	int korean_ = 0, english_ = 0, math_ = 0;
};
//<시 오름차순, >시 내림차순
bool func(INFO i, INFO j)
{
	if (i.korean_ == j.korean_)
	{
		if (i.english_ == j.english_)
		{
			if (i.math_ == j.math_)
			{
				return i.name_ < j.name_;
			}
			else
				return i.math_ > j.math_;
		}
		else
			return i.english_ < j.english_;
	}
	else
		return i.korean_ > j.korean_;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N = 0;
	INFO info;
	
	string name;
	int korean = 0, english = 0, math = 0;
	cin >> N;
	//tuple로도 가능하다.
	vector<INFO>v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> name >> korean >> english >> math;
		info.name_ = name;
		info.korean_ = korean;
		info.english_ = english;
		info.math_ = math;
		v.push_back(info);
	}


	sort(v.begin(), v.end(),func);

	for (int i = 0; i < N; i++)
	{	
		cout << v[i].name_ << " " << '\n';
	}
	
	return 0;
}