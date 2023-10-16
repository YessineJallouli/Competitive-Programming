#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int n, int k) {
   int idD = 0;
   int nb = 0;
   for (int i = 0; i < n; i++) {
      if (s[i] == '*') {
         idD = i;
         s[i] = 'X';
         nb++;
         break;
      }
   }
   for (int i = idD; i < n; i++) {
      if (s[i] == 'X') {
         int pos = -1;
         for (int j = i+1; j-i <= k && j < n; j++) {
            if (s[j] == '*') {
               pos = j;
            }
         }
         if (pos != -1) {
            s[pos] = 'X';
            nb++;
         }
      }
   }
   return nb;
}
int main() {
   int T; cin >> T;
   while (T--) {
      int n,k; cin >> n >> k;
      string s; cin >> s;
      string s1 = s;
      reverse(s1.begin(), s1.end());
      cout << min(solve(s,n,k), solve(s1,n,k)) << endl;
   }
}