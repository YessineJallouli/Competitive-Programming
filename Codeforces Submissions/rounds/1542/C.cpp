/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

ll pcm(ll a, ll b) {
   return (a*b)/__gcd(a,b);
}
int main() {
   SaveTime
   int T; cin >> T;
   vector<ll> v;
   for (int i = 2; i <= 42; i++) {
      v.push_back(i);
   }
   int mod = 1e9+7;
   while (T--) {
      ll n; cin >> n;
      int nb = v.size();
      ll ppcm = 1;
      ll ans = 0;
      for (int i = 0; i < nb; i++) {
         if (i == 0) {
            ans+= (n-(n/2))*2;
            continue;
         }
         ppcm = pcm(ppcm, v[i-1]);
         ans = (ans + (((n/ppcm)-(n/pcm(ppcm,v[i])))*v[i]))%mod;
      }
      cout << ans << endl;
   }
}