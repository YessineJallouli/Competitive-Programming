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
   ll T; cin >> T;
   while (T--) {
      string s; cin >> s;
      sort(s.begin(), s.end());
      int n = s.size();
      if (n < 3 || s[0] == s[n-1]) {
         cout << s << endl;
         continue;
      }
      map<int,int> cnt;
      for (int i = 0; i < n; i++) {
         cnt[s[i]-'a']++;
      }
      bool one = false;
      int idd = -1;
      for (int i = 0; i < 26; i++) {
         if (cnt[i] == 1) {
            one = true;
            for (int j = 0; j < n; j++) {
               if (s[j] == i+'a') {
                  idd = j;
                  break;
               }
            }
            break;
         }
      }
      if (one) {
         cout << s[idd] << s.substr(0, idd) << s.substr(idd+1, n-idd) << endl;
         continue;
      }
      int nb1 = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] != s[i+1]) {
            nb1 = i+1;
            break;
         }
      }
      int nn = n-nb1;
      if (nb1-nn < 3) {
         string ans = "";
         ans+= s[0];
         int nb2 = min(nb1-1, n-nb1);
         int fx = 1+2*nb2;
         int id = nb1;
         nb1--;
         for (int i = 0; i < nb2; i++) {
            ans+= s[0];
            ans+= s[id];
            id++;
         }
         nb1-= nb2;
         fx += nb1;
         for (int i = 0; i < nb1; i++)
            ans+= s[0];
         for (int i = fx; i < n; i++)
            ans+= s[i];
         cout << ans << endl;
      }
      else {
         if (s[nb1] == s[n-1]) {
            cout << s[0];
            for (int i = nb1; i < n; i++)
               cout << s[i];
            for (int i = 1; i < nb1; i++)
               cout << s[i];
            cout << endl;
            continue;
         }
         cout << s[0] << s[nb1];
         for (int i = 0; i < nb1-1; i++)
            cout << s[0];
         int id1 = -1;
         for (int i = nb1; i < n-1; i++) {
            if (s[i] != s[i+1]) {
               id1 = i+1;
               break;
            }
         }
         if (id1 != -1)
            cout << s[id1];
         for (int i = nb1+1; i < n; i++)
            if (i != id1)
               cout << s[i];
         cout << endl;
      }
   }
}