#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int N = 2e5+7;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      int ans = s[n-1]-'0';
      for (int i = 0; i < n-1; i++) {
         if (s[i] == '0')
            continue;
         ans+= s[i]-'0'+1;
      }
      cout << ans << '\n';
   }
}