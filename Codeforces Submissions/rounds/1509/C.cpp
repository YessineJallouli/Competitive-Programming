#include <bits/stdc++.h>
using namespace std;

const int mx = 2001;
long long dp[mx][mx];
long long num[mx];

long long int retMin(int a, int b) {
   if (a == b)
      return dp[a][b] = 0;
   if (dp[a][b] != -1)
      return dp[a][b];
   dp[a][b] = num[b]-num[a] + min(retMin(a+1, b), retMin(a, b-1));
   return dp[a][b];
}

int main()
{
   int n; cin >> n;
   for (int i = 0; i < n; i++)
      cin >> num[i];
   sort(num, num+n);
   memset(dp, -1, sizeof dp);
   cout << retMin(0, n-1);
}