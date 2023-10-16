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
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n  = s.size();
      string s1 = s;
      string s2 = s;
      for (int i = 0; i < n; i++) {
         if (s1[i] == '?' && i%2 == 0)
            s1[i] = '0';
         else if (s1[i] == '?' && i%2 == 1)
            s1[i] = '1';
      }
      for (int i = 0; i < n; i++) {
         if (s2[i] == '?' && i%2 == 1)
            s2[i] = '0';
         else if (s2[i] == '?' && i%2 == 0)
            s2[i] = '1';
      }
      //cout << s1 << ' ' << s2 << endl;
      int sc1 = 0;
      int sc2 = 0;
      int ans1 = 0;
      for (int i = 0; i < n; i++) {
         if (s1[i] == '1' && i%2 == 0)
            sc1++;
         if (s1[i] == '1' && i%2 == 1)
            sc2++;
         int rem1 = 5-(i+2)/2;
         if (sc1+rem1 < sc2) {
            ans1 = i+1;
            break;
         }
         int rem2 = 5-(i+1)/2;
         if (sc2+rem2 < sc1) {
            ans1 = i+1;
            break;
         }
      }
      int ans2 = 0;
      sc1 = 0, sc2 = 0;
      for (int i = 0; i < n; i++) {
         if (s2[i] == '1' && i%2 == 0)
            sc1++;
         if (s2[i] == '1' && i%2 == 1)
            sc2++;
         int rem1 = 5-(i+2)/2;
         if (sc1+rem1 < sc2) {
            ans2 = i+1;
            break;
         }
         int rem2 = 5-(i+1)/2;
         if (sc2+rem2 < sc1) {
            ans2 = i+1;
            break;
         }
      }
      if (ans1 == 0 && ans2 == 0) {
         cout << 10 << endl;
      }
      else {
         if (ans1 == 0)
            cout << ans2 << endl;
         else if (ans2 == 0)
            cout << ans1 << endl;
         else
            cout << min(ans1, ans2) << endl;
      }
   }
}