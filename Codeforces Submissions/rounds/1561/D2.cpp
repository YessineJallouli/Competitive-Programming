#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 4e6+7;

ll dp[mx];
ll cum[mx];
int mod;

int main() {
   int n; cin >> n >> mod;
   memset(cum, 0, sizeof cum);
   cum[n] = 1;
   dp[n] = 1;
   for (int i = n-1; i >= 1; i--) {
      dp[i] = cum[i+1];
      for (int j = 2*i; j <= n; j+= i) {
         int k = min(j+j/i-1, n);
         dp[i] = (dp[i] + cum[j] - cum[k+1] + mod) % mod;
      }
      cum[i] += cum[i+1] + dp[i];
      cum[i]%= mod;
   }
   cout << dp[1];
}