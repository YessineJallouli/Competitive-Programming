#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> v, v1;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a == 2)
				a = -1;
			v.push_back(a);
			sum += a;
		}
		reverse(v.begin(), v.end());
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a == 2)
				a = -1;
			v1.push_back(a);
			sum += a;
		}
		if (sum == 0)
		{
			cout << 0 << '\n';
			continue;
		}
		int s = 0;
		map<int, int> m;
		for (int i = 0; i < n; i++)
		{
			s += v[i];
			if (m[s] == 0 && s != 0)
				m[s] = i + 1;
		}
		s = 0;
		int ansM = INT_MAX;
		if (m[sum] != 0)
		   ansM = m[sum];
		for (int i = 0; i < n; i++)
		{
			s += v1[i];
			int r = sum - s;
			if (r == 0 || m[r] != 0)
			   ansM = min(ansM, m[r] + i + 1);
		}
		cout << ansM << '\n';
	}
}