#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 61;
long long dp[mx];

long long nb(int n) {
   if (dp[n] != -1)
      return dp[n];
   if (n == 1)
      return dp[1] = 1;
   long long ans = 0;
   for (int i = 1; i < n; i++) {
      ans = ans + nb(n-i);
   }
   return dp[n] = ans+1;
}


int main() {
   memset(dp, -1, sizeof dp);
   nb(60);
   int N,M;
   cin >> N >> M;
   if (N < 2 || M < 2)
      cout << 0;
   else
      cout << (dp[N]+dp[M]-1)*2;
}