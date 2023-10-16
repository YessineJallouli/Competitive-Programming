#include <iostream>
using namespace std;

const int m = 998244353;

long long power_of_ten[200000];

int solve(int n, int k)
{
	if (n == k)
	   return 10;
	long long ans = 2*10*9*power_of_ten[n-k-1];
	if (n-k-2 >= 0)
		ans+= 10*9*9*power_of_ten[n-k-2]*(n-k-1);
	ans%= m;
	return ans;
}

int main()
{
	int n; cin >> n;
    power_of_ten[0] = 1;
	for (int i = 1; i <= n; i++)
		power_of_ten[i] = (power_of_ten[i-1]*10)%m;
	for (int i = 1; i <= n; i++)
		cout << solve(n,i) << ' ';
}