#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   string ch = "twone";
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n = s.length();
      bool remov[n];
      memset(remov, false, sizeof remov);
      string sub = "";
      for (int i = 0; i < n; i++) {
         sub+= s[i];
         if (sub.length() < 5)
            continue;
         if (sub == ch)
            remov[i-2] = true;
         sub.erase(sub.begin());
      }
      string s1 = "";
      int ans = 0;
      for (int i = 0; i < n; i++) {
         if (!remov[i])
            s1+=s[i];
         else
            ans++;
      }
      sub = "";
      for (int i = 0; i < n; i++) {
         sub+= s[i];
         if (sub.length() < 3)
            continue;
         if (sub == "one" && ! remov[i] && !remov[i-1] && ! remov[i-2]) {
            remov[i-1] = true;
            ans++;
         }
         if (sub == "two" && ! remov[i] && !remov[i-1] && ! remov[i-2]) {
            remov[i-1] = true;
            ans++;
         }
         sub.erase(sub.begin());
      }
      cout << ans << endl;
      for (int i = 0; i < n; i++) {
         if (remov[i])
            cout << i+1 << ' ';
      }
      cout << endl;
   }
}