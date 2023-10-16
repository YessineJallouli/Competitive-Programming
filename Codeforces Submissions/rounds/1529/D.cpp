#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

int main() {
   ///Counting all divisors from 1 to N
   int n; cin >> n;
   int div[n+1];
   memset(div, 0, sizeof div);
   for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j+= i) {
         div[j]++;
      }
   }
   int mod = 998244353;
   int prefixsum = 0;
   int dp = 0;
   for (int i = 1; i <= n; i++) {
      dp = (dp+prefixsum)%mod;
      prefixsum = (dp + div[i])%mod;
   }
   cout << prefixsum;
}