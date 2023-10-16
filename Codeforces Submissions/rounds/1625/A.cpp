#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
    SaveTime
   int T; cin >> T;
   while (T--) {
       int n,k; cin >> n >> k;
       int a[n];
       for (int i = 0; i < n; i++) {
           cin >> a[i];
       }
       int nb[31];
       memset(nb, 0, sizeof nb);
       for (int i = 0; i < n; i++) {
           for (int bit = 0; bit < 31; bit++) {
               if (a[i] & (1 << bit)) {
                   nb[bit]++;
               }
           }
       }
       int ans = 0;
       for (int bit = 0; bit < 31; bit++) {
           if (nb[bit] > n/2)
               ans+= (1<<bit);
       }
       cout << ans << '\n';
   }
}