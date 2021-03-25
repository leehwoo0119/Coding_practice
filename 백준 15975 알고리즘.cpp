#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

multimap<long long, long long>m;
vector<long long>v;
vector<long long>pluss;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N = 0;
	long long x = 0, y = 0;
	
	cin >> N;

	while (N--)
	{
		cin >> x >> y;

		m.insert(make_pair(y, x));
	}
	
	int totaltmp = 0;
	long long cnt = 0;
	int loop = m.size();
	auto startPoint = m.begin();
	int prevKey = startPoint->first;
	while (loop)
	{
		if (loop != m.size()) prevKey = prev(startPoint)->first;
		if (prevKey == startPoint->first)
		{
			v.push_back(startPoint->second);
		}
		if (prevKey != startPoint->first || cnt== m.size()-1)
		{
			
			sort(v.begin(), v.end());
			for (int i = 0; i < v.size(); i++)
			{			

				int leftLine = 0, rightLine = 0;
				if (i != 0)leftLine = v[i] - v[i - 1];
				if(i!= v.size() - 1)rightLine = (v[i] - v[i + 1]) * -1;
				//cout << "L: "<< leftLine<<", "<<"R: "<< rightLine << endl;
				if (rightLine == 0)rightLine = leftLine;
				if (leftLine == 0)leftLine = rightLine;
				pluss.push_back(min(leftLine, rightLine));
			}
			for (int x : pluss)
				totaltmp += x;
			pluss.clear();
			v.clear();
			v.push_back(startPoint->second);
		}
		loop--;
		startPoint++;
		cnt++;
	}
	cout << totaltmp;
	return 0;
}

