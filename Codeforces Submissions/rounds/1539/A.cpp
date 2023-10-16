/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n,x,t; cin >> n >> x >> t;
      if (x > t) {
         cout << 0 << endl;
         continue;
      }
      else {
         ll nb = min(t/x, n-1);
         ll ans = (n-nb)*nb + (nb)*(nb-1)/2;
         cout << ans << endl;
      }
   }
}