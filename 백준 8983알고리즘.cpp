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
		//모든 사로를 비교하면 시간초과가나온다.lower_bound를 이용해 동물 x축 이상 or 그 -1로 범위를 줄이자
		auto upper = lower_bound(SadePos.begin(), SadePos.end(), aniit->first);
		auto lower = upper - 1;
		
		cout << aniit->first << ": ";
		cout << "lower: " << *lower  << " ";
		cout << "upper: " << *upper << endl;
		
		//두경우를 비교해서 작은경우가 사정거리 안이면 둘중하나는 무조건 사정거리안이다
		if (min((abs(*lower - aniit->first) + aniit->second),
			(abs(*upper - aniit->first) + aniit->second))
			<= LimDis)
			cnt++;	
	}
	cout << cnt;
	return 0;
}

