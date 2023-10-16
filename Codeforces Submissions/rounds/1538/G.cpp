/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

bool can(ll m, ll x, ll y, ll a, ll b) {
   ll mn = ceil((y-m*a)*1.0/(b-a));
   ll mx = floor((x-m*b)*1.0/(a-b));
   return ((x-m*b >= 0) && (mn <= m) && (mx >= mn));
}

int main()
{
   SaveTime
   ll T; cin >> T;
   while (T--) {
      ll x,y,a,b; cin >> x >> y >> a >> b;
      if (a == b) {
         cout << min(x,y)/a << endl;
         continue;
      }
      if (a < b)
         swap(a,b);
      ll sumMax = (x+y)/(a+b);
      ll sumMin = 0;
      while (sumMin < sumMax-1) {
         ll Milieu = (sumMax + sumMin)/2;
         if (can(Milieu, x,y,a,b)) {
            sumMin = Milieu;
         }
         else
            sumMax = Milieu-1;
      }
      if (can(sumMax, x,y,a,b))
         cout << sumMax << endl;
      else
         cout << sumMin << endl;
   }
}