#include<bits/stdc++.h>
#define MOD 1e9+7
#define ull long long
#define ll unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   ll n, k;
   cin >> n >> k;
   ll num[n];
   for (ll i = 0; i < n; i++) {
      cin >> num[i];
   }
   sort(num, num+n);
   vector<map<ll,ll>> modulo_by_number(11);
   for (ll i = 0; i < n; i++) {
      ll h = num[i]% k;
      string s = to_string(num[i]);
      ll L = s.size();
      modulo_by_number[L][h]++;
   }
   ll ans = 0;
   for (ll i = 0; i < n; i++) {
      ll N = num[i];
      ll h = N%k;
      string s = to_string(N);
      ll L = s.size();
      ll co = 10;
      for (ll j = 0; j < 10; j++) {
         N*= co;
         ll r = N%k;
         ll r1 = (k- r) % k;
         ans+= modulo_by_number[j+1][r1];
         if (r1 == h && L == j+1)
            ans--;
      }
   }
   cout << ans;
}