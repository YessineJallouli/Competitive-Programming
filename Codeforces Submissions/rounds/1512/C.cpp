#include <bits/stdc++.h>
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int a, b; cin >> a >> b;
      string s; cin >> s;
      int n = s.size();
      bool bb = true;
      for (int i = 0; i < n; i++) {
         if (s[i] != s[n-i-1] && s[i] != '?' && s[n-i-1] != '?')
            bb = false;
      }
      if (!bb || a+b != n) {
         cout << -1 << endl;
         continue;
      }
      if (a%2 == 1 && b%2 == 1) {
         cout << -1 << endl;
         continue;
      }
      for (int i = 0; i < n; i++) {
         if (s[i] == '?' && s[n-i-1] != '?') {
            s[i] = s[n-i-1];
         }
      }
      int nba = 0;
      int nbb = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '1')
            nbb++;
         else if (s[i] == '0')
            nba++;
      }
      if (nbb > b || nba > a) {
         cout << -1 << endl;
         continue;
      }
      for (int i = 0; 2*(i+1) <= n; i++) {
         if (s[i] == '?' && a-nba > 1) {
            nba+= 2;
            s[i] = '0';
            s[n-i-1] = '0';
         }
         else if (s[i] == '?' && b-nbb > 1) {
            nbb+= 2;
            s[i] = '1';
            s[n-i-1] = '1';
         }
      }
      if (n%2 == 1 && s[n/2] == '?') {
         if (nbb != b) {
            s[n/2] = '1';
         }
         else if (nba != a) {
            s[n/2] = '0';
         }
      }
      bb = true;
      nba = 0, nbb = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] != s[n-i-1] && s[i] != '?' && s[n-i-1] != '?')
            bb = false;
      }
      for (int i = 0; i < n; i++) {
         if (s[i] == '1')
            nbb++;
      }
      if (!bb || a+b != n) {
         cout << -1 << endl;
         continue;
      }
      if (nbb != b) {
         cout << -1 << endl;
         continue;
      }
      cout << s << endl;
   }
}