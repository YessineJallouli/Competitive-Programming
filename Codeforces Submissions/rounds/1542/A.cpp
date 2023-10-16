/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int nb = 0;
      for (int i = 0; i < 2*n; i++) {
         int x; cin >> x;
         if (x%2 == 1) {
            nb++;
         }
      }
      if (nb == n) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}