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
      int x,y; cin >> x >> y;
      if (x*2 <= y)
         cout << x << ' ' << 2*x << '\n';
      else
         cout << -1 << ' ' << -1 << '\n';
   }
}