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
      string s, t; cin >> s >> t;
      int n = s.size();
      bool ans = false;
      for (int chip = 0; chip < n; chip++) {
         for (int id = chip; id < n; id++) {
            string ch = s.substr(chip, id-chip+1);
            int j = id-1;
            if (j != -1) {
               while (ch.size() < t.size()) {
                  ch+= s[j];
                  j--;
                  if (j == -1)
                     break;
               }
            }
            if (ch == t)
               ans = true;
         }
      }
      if (ans) {
         cout << "YES" << "\n";
      }
      else
         cout << "NO" << "\n";
   }
}