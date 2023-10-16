/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      string s1 = s;
      sort(s1.begin(), s1.end());
      int ans = 0;
      for (int i = 0; i < s1.size(); i++) {
         if (s[i] != s1[i])
            ans++;
      }
      cout << ans << '\n';
   }
}