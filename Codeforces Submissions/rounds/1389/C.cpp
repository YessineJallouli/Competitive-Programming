#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;



int main()
{
   int T; cin >> T;
   while (T--) {
      string s;
      cin >> s;
      int n = s.length();
      int dig[10][n+1];
      memset(dig, 0, sizeof dig);
      for (int i = 0; i <= 9; i++) {
         for (int j = 0; j < n; j++) {
            int num = s[j] - '0';
            dig[i][j+1] = dig[i][j];
            if (num == i)
               dig[i][j+1]++;
         }
      }
      int ans = 0;
      for (int i = 0; i <= 9; i++)
         ans = max(ans, dig[i][n]);
      int prev;
      for (int i = 0; i <= 9; i++) {
         for (int j = 0; j <= 9; j++) {
            prev = 0;
            if (i == j)
               continue;
            int dd = 0;
            for (int k = 1; k < n; k++) {
               int num = s[k] - '0';
               if (num != i)
                  continue;
               int nb = dig[j][k+1] - dig[j][prev];
               if (nb > 0)
                  dd+=2;
               prev = k;
            }
            ans = max(ans, dd);
         }
      }
      cout << n-ans << '\n';
   }
}