#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      ll x,y,a,b; cin >> x >> y >> a >> b;
      ll sum = 0;
      if (x > y)
         swap(x,y);
      if (b <= 2*a) {
         sum+= x*b;
         sum+= (y-x)*a;
      }
      else
      {
         sum+= (y+x)*a;
      }
      cout << sum << endl;
   }
}