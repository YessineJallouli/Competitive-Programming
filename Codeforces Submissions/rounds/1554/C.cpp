/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      if (m < n) {
         cout << 0 << '\n';
         continue;
      }
      int X = (m & (m+1));
      if (X == 0) {
         cout << m+1 << '\n';
         continue;
      }
      int id = 1;
      int nb = 0;
      while (id < m) {
         id*= 2;
         nb++;
      }
      if (id != m) {
         id/= 2;
         nb--;
      }
      int ans = 0;
      bool check = false;
      int NB = nb;
      int lastId = -1;
      for (int i = id; i > 0; i/= 2) {
         int nBit = (n & (1 << NB)) != 0;
         int mBit = (m & (1 << NB)) != 0;
         //cout << nBit << ' ' << mBit << '\n';
         if (nBit == 1 && mBit == 0) {
            check = true;
            break;
         }
         else if (nBit == 0 && mBit == 0) {
            lastId = i;
         }
         else if (nBit == 0 && mBit == 1) {
            //equality
            ans+= (1 << NB);
         }
         NB--;
      }
      if (check) {
         cout << ans << '\n';
         continue;
      }
      NB = nb;
      ans = 0;
      for (int i = id; i > 0; i/= 2) {
         int nBit = (n & (1 << NB)) != 0;
         int mBit = (m & (1 << NB)) != 0;
         if (nBit == 0 && mBit == 0 && i == lastId) {
            ans+= (1 << NB);
            break;
         }
         else if (nBit == 0 && mBit == 1) {
            //equality
            ans+= (1 << NB);
         }
         NB--;
      }
      cout << ans << '\n';
   }
}