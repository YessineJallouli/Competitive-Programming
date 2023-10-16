#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      ll N = n;
      vector<ll> v;
      for (ll i = 2; i*i <= N; i++) {
         while (n% i == 0) {
            n/= i;
            v.push_back(i);
         }
      }
      if (n != 1)
         v.push_back(n);
      map<ll, int> nb;
      ll num = -1;
      ll mx = 0;
      for (int i = 0; i < v.size(); i++) {
         nb[v[i]]++;
         if (nb[v[i]] > mx) {
            mx = nb[v[i]];
            num = v[i];
         }
      }
      cout << mx << endl;
      ll p = 1;
      for (int i = 0; i < mx-1; i++) {
         cout << num << ' ';
         p*= num;
      }
      cout << N/p << ' ';
      cout << endl;
   }
}