#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int k; cin >> k;
      if (n <= k) {
         cout << 1 << '\n';
         continue;
      }
      int ans = INT_MAX;
      for (int i = 2; i*i <= n; i++) {
         if (n%i == 0) {
            int a = i; int b = n/i;
            int mini = max(a,b);
            if (mini <= k)
               ans = min(ans, min(a,b));
            mini = min(a,b);
            if (mini <= k)
               ans = min(ans, max(a,b));
         }
      }
      if (ans == INT_MAX)
         cout << n << '\n';
      else
         cout << ans << '\n';
   }
}