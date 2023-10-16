#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int n; cin >> n;
   ll sum = 0;
   ll mx = 0;
   for (int i = 0; i < n; i++) {
      ll x; cin >> x; sum+= x;
      mx = max(mx, x);
   }
   ll ans = sum/(n-1);
   if (sum%(n-1) != 0)
      ans++;
   cout << max(ans,mx);
}