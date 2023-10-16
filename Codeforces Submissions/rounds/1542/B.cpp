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
      ll n,a,b; cin >> n >>  a >> b;
      bool can = false;
      for (ll i = 1; i <= n; i*= a) {
         ll x = i;
         if ((n-x)%b == 0)
            can = true;
         if (a == 1)
            break;
      }
      if (can)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}