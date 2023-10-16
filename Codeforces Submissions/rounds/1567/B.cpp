#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 3e5+7;

int main() {
   SaveTime
   int Xor[mx];
   Xor[0] = 0;
   for (int i = 1; i < mx; i++) {
      Xor[i] = Xor[i-1]^i;
   }
   int T; cin >> T;
   while (T--) {
      int mex, x; cin >> mex >> x;
      int xr = Xor[mex-1];
      if (xr == x) {
         cout << mex << '\n';
      }
      else {
         int missing  = x^xr;
         if (missing == mex)
            cout << mex+2 << '\n';
         else
            cout << mex+1 << '\n';
      }
   }
}