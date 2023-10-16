#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      int ans = 0;
      bool b = true;
      bool b1 = true;
      for (int i = 0; i < n; i++) {
         if (s[i] == '>')
            b = false;
      }
      for (int i = 0; i < n; i++) {
         if (s[i] == '<')
            b1 = false;
      }
      if (b) {
         cout << n << endl;
         continue;
      }
      if (b1) {
         cout << n << endl;
         continue;
      }
      //int ans = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '-') {
            ans++;
            continue;
         }
         if (i == 0) {
            if (s[n-1] == '-') {
               ans++;
               continue;
            }
         }
         else if (s[i-1] == '-') {
            ans++;
            continue;
         }
         int pred = i-1;
         if (pred < 0)
            pred+=n;
      }
      cout << ans << endl;
   }
}