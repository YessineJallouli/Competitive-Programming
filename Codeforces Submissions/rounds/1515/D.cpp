#include <bits/stdc++.h>
using namespace std;


int main() {

	int T;
	cin >> T;
	while (T--) {
      int n,l,r; cin >> n >> l >> r;
      vector<int> nb1(n+1, 0);
      vector<int> nb2(n+1, 0);
      for (int i = 0; i < l; i++) {
         int a; cin >> a;
         nb1[a]++;
      }
      for (int i = 0; i < r; i++) {
         int a; cin >> a;
         nb2[a]++;
      }
      for (int i = 1; i <= n; i++) {
         int mn = min(nb1[i], nb2[i]);
         nb1[i]-= mn;
         nb2[i]-= mn;
      }
      if (r > l) {
         nb1.swap(nb2);
         swap(l,r);
      }
      int min_cost = (l-r)/2;
      int ans = min_cost;
      for (int i = 1; i <= n; i++) {
         if (nb1[i] > 1) {
            int nb = (nb1[i])/2;
            if (nb < min_cost) {
               min_cost-= nb;
               nb1[i]-= nb*2;
            }
            else {
               nb1[i]-= min_cost*2;
               min_cost = 0;
               break;
            }
         }
      }
      if (min_cost != 0) {
         for (int i = 1; i <= n; i++) {
            if (nb1[i] == 0) {
               continue;
            }
            if (nb1[i] < min_cost) {
               int x = min_cost;
               min_cost-= nb1[i];
               nb1[i] = 0;
            }
            else {
               nb1[i]-= min_cost;
               min_cost = 0;
               break;
            }
         }
      }
      for (int i = 1; i <= n; i++) {
         ans+= nb1[i];
      }
      cout << ans << endl;
	}
}