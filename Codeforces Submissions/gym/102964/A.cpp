#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   long long mod = 1e9+7;
   int n; cin >> n;
   long long a[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]*= a[i];
   }
   sort(a,a+n);
   for (int i = 0; i < n; i++) {
      a[i] = a[i]%mod;
   }
   long long cumulative_sum[n+1];
   cumulative_sum[0] = a[0];
   for (long long i = 1; i <n; i++) {
      cumulative_sum[i] = (a[i]+cumulative_sum[i-1])%mod;
   }
   long long ans = 0;
   for (long long i = n-1; i >= 1; i--) {
      ans = (ans + (i) * a[i] - cumulative_sum[i-1])%mod;
      if (ans < 0)
         ans+= mod;
   }
   cout << ans;
}