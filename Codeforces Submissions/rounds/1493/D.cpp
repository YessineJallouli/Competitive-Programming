#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9+7;

const int mxx = 200002;
ll sieve[mxx];

vector<ll> factorize(ll n) {
   vector<ll> v1;
   while (n != 1) {

      v1.push_back(sieve[n]);
      n/= sieve[n];
   }
   return v1;
}

int main() {
   ll n,q; cin >> n >> q;
   ll a[n];
   int mx = 200002;
   vector<map<ll,ll>> nb(mx);
   vector<map<ll,ll>> pw(mx);
   for (int i = 0; i < mx; i++)
      sieve[i] = 1;
   for (int i = 2; i < mx; i++) {
      if (sieve[i] == 1) {
         for (int j = i; j < mx; j+=i) {
            if (sieve[j] == 1)
               sieve[j] = i;
         }
      }
   }
   ll gcd = 1;
   for (ll i = 0; i < n; i++) {
      cin >> a[i];
      vector<ll> v = factorize(a[i]);
      for (ll x : v) {
         nb[i][x]++;
         pw[x][nb[i][x]]++;
         if (pw[x][nb[i][x]] == n)
            gcd = (gcd*x)%mod;
      }
   }
   for (int i = 0; i < q; i++) {
      int id; ll a;
      cin >> id >> a; id--;
      vector<ll> v = factorize(a);
      for (ll x : v) {
         //cout << x << endl;
         nb[id][x]++;
         pw[x][nb[id][x]]++;
         if (pw[x][nb[id][x]] == n)
            gcd = (gcd*x)%mod;
      }
      cout << gcd << endl;
   }
}