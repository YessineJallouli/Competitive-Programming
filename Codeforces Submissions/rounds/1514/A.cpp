#include <bits/stdc++.h>
#define ll long long
using namespace std;

int mod = 1e9+7;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      bool b = false;
      for (int i = 0; i < n; i++) {
            int x = num[i];
            int d = sqrt(x);
            if (d*d != x)
               b = true;
      }
      if (b) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}