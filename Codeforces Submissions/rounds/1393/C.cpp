#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int nb[n+1];
      memset(nb, 0, sizeof nb);
      for (int i = 0; i < n; i++) {
         int a; cin >> a;
         nb[a]++;
      }
      sort(nb, nb+n+1);
      int mx = nb[n];
      int cnt = 0;
      for (int i = n-1; i >= 0; i--)
         cnt += (nb[i] == mx);
      int r = n-mx*(cnt+1);
      cnt+= r/(mx-1);
      cout << cnt << '\n';

   }
}