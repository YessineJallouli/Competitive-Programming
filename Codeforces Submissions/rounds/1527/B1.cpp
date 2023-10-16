#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      int nb = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '0')
            nb++;
      }
      if (nb == 0) {
         cout << "DRAW" << endl;
         continue;
      }
      if (n%2 == 0 || s[n/2] == '1') {
         cout << "BOB" << endl;
      }
      else {
         if (nb == 1) {
            cout << "BOB" << endl;
         }
         else
            cout << "ALICE" << endl;
      }
   }
}