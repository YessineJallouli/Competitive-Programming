#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k;
      string s; cin >> s;
      if (k*2 >= n) {
         cout << "NO" << endl;
         continue;
      }
      if (k == 0) {
         cout << "YES" << endl;
         continue;
      }
      int i = 0;
      int j = n-1;
      int nb = 0;
      while (s[i] == s[j] && i <= j) {
         i++;
         j--;
         nb++;
      }
      if (nb >= k) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}