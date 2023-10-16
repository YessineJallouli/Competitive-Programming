#include<bits/stdc++.h>
#define SaveTime ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

ll solve(const ll r, const int P, const int a, const int b)
{
   if (r < 1)
      return 0;
   ll maxi = max({a,b});
   ll K = (r/P);
   ll ans = K*maxi-1;
   if (r % P < maxi)
      ans+= (r%P)+1;
   else
      ans+= maxi;
   return ans;
}

ll pcm(ll a, ll b) {
   return (a*b)/__gcd(a,b);
}

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      ll a, b, q; cin >> a >> b >> q;
      ll P = pcm(a,b);
      for (int i = 0; i < q; i++)
      {
         ll n1, n2; cin >> n1 >> n2;
         ll egality = solve(n2, P, a,b) - solve(n1-1, P, a, b);
         cout << n2-n1+1-egality << ' ';
      }
      cout << '\n';
   }
}