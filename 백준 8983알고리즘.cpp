#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> //abs
using namespace std;
vector<long long>SadePos;
vector<pair<long long, long long>>AniPos;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long SadeNum = 0, SadePosX = 0;
	long long AniNum = 0, AniPosX = 0, AniPosY = 0;
	long long LimDis = 0;
	long long cnt = 0;

	cin >> SadeNum >> AniNum >> LimDis;

	for (long long i = 0; i < SadeNum; i++)
	{
		cin >> SadePosX;
		SadePos.push_back(SadePosX);
	}
	/*SadePos.push_back(-1000000001);
	SadePos.push_back(1000000001);*/
	sort(SadePos.begin(), SadePos.end());
	for (long long i = 0; i < AniNum; i++)
	{
		cin >> AniPosX >> AniPosY;
		AniPos.push_back(make_pair(AniPosX, AniPosY));
	}
	sort(AniPos.begin(), AniPos.end());

	for (auto aniit = AniPos.begin(); aniit != AniPos.end(); aniit++)

	{
		//��� ��θ� ���ϸ� �ð��ʰ������´�.lower_bound�� �̿��� ���� x�� �̻� or �� -1�� ������ ������
		auto upper = lower_bound(SadePos.begin(), SadePos.end(), aniit->first);
		auto lower = upper - 1;
		
		cout << aniit->first << ": ";
		cout << "lower: " << *lower  << " ";
		cout << "upper: " << *upper << endl;
		
		//�ΰ�츦 ���ؼ� ������찡 �����Ÿ� ���̸� �����ϳ��� ������ �����Ÿ����̴�
		if (min((abs(*lower - aniit->first) + aniit->second),
			(abs(*upper - aniit->first) + aniit->second))
			<= LimDis)
			cnt++;	
	}
	cout << cnt;
	return 0;
}

