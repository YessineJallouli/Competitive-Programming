#include <bits/stdc++.h>
#define ll long long

using namespace  std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i <n; i++)
         cin >> num[i];
      sort(num, num+n);
      int ans = 1;
      int mx = 0;
      int diffMin = INT_MAX;
      for (int i = 1; i < n; i++) {
         if (abs(num[i]-num[i-1]) >= num[i] && diffMin >= num[i]) {
            ans++;
         }
         else
            break;
         diffMin = min(num[i]-num[i-1], diffMin);
      }
      cout << ans << endl;
   }
}