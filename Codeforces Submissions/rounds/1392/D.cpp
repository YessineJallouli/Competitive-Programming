#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      bool b = true;
      for (int i = 0; i < n-1; i++) {
         if (s[i] != s[i+1])
            b = false;
      }
      if (b) {
         int ans = n/3;
         if (n%3 != 0)
            ans++;
         cout << ans << endl;
         continue;
      }
      while(s[0] == s[n-1]) {
         s.erase(s.begin());
         s+= s[n-2];
      }
      char c = s[0];
      int nb = 0;
      int ans = 0;
      for (int i = 0; i <n; i++) {
         if (s[i] == c) {
            nb++;
            continue;
         }
         ans+= nb/3;
         if (c == 'R')
            c = 'L';
         else
            c = 'R';
         nb = 1;
      }
      ans+= nb/3;
      cout << ans << endl;
   }
}