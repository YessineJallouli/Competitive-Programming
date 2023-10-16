#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1e5+7;
int main() {
   vector<int> v;
   ll n; cin >> n;
   ll p = 1;
   for (ll i = 1; i <= n; i++) {
      if (__gcd(i, n) == 1) {
         v.push_back(i);
         p = (p*i)%n;
      }
   }
   if (p != 1)
      v.pop_back();
   cout << v.size() << endl;
   for (int i  : v)
      cout << i << ' ';
}