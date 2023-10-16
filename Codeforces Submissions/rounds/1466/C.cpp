#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n = s.size();
      int ans = 0;
      int i = 0;
      while (i < n) {
         if (i+2 < n) {
            if (s[i] == s[i+1] && s[i+1] == s[i+2]) {
               ans+= 2;
               i+= 3;
               continue;
            }
         }
         if (i+2 < n) {
            if (s[i] == s[i+2]) {
               if (i+3 < n) {
                  if (s[i+1] != s[i+3]) {
                     ans++;
                     i+= 3;
                  }
                  else {
                     ans+= 2;
                     i+= 4;
                  }
                  continue;
               }
               else {
                  ans++;
                  i+=2;
               }
               continue;
            }
         }
         if (i+1 < n) {
            if (s[i] == s[i+1]) {
               ans++;
               i+=2;
               continue;
            }
         }
         i++;
      }
      cout << ans<< endl;
   }
}