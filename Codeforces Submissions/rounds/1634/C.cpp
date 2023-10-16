#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false), cin.tie(0);
   int T; cin >> T;
   while (T--) {
       int n,k; cin >> n >> k;
       int lastp = 2;
       int lastimp = 1;
       int ans[n][k];
       int mx = 0;
       for (int i = 0; i < n; i++) {
           int d;
           if (i%2 == 0)
               d = lastimp;
           else
               d = lastp;
           for (int j = 0; j < k; j++) {
               ans[i][j] = d+2*j;
               mx = max(mx, ans[i][j]);
               if (i%2 == 0)
                   lastimp = d+2*j+2;
               else
                   lastp = d+2*j+2;
           }
       }
       if (mx != n*k) {
           cout << "NO\n";
           continue;
       }
       cout << "YES\n";
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < k; j++) {
               cout << ans[i][j] << ' ';
           }
           cout << '\n';
       }
   }
}