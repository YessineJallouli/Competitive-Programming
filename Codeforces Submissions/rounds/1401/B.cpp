#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
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
      int a,b,c; cin >> c >> b >> a;
      int x,y,z; cin >> z >> y >> x;
      ll ans = 0;
      int mn = min(a,y);
      ans+= 2*mn;
      y-= mn; a-=mn;
      if (a > 0) {
         mn = min(a, x);
         x-= mn;
         a-= mn;
      }
      mn = min(x, c);
      c-= mn;
      x-= mn;
      mn = min(x, b);
      ans-= 2*mn;
      cout << ans << '\n';
   }
}