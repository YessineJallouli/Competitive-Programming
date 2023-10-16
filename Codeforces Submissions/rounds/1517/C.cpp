#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int n; cin >> n;
   int ans[n][n];
   int p[n];
   memset(ans, 0, sizeof ans);
   for (int i = 0; i < n; i++) {
      cin >> p[i];
      ans[i][i] = p[i];
   }
   for (int i = 0; i < n; i++) {
      int rem = p[i]-1;
      int nb = 0;
      int I = i; int J = i;
      while (nb != rem) {
         if (J != 0) {
            if (ans[I][J-1] == 0) {
               J--;
            }
            else
               I++;
         }
         else
            I++;
         nb++;
         ans[I][J] = p[i];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++)
         cout << ans[i][j] << ' ';
      cout << endl;
   }

}