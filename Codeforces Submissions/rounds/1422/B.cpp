#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, m; cin >> n >> m;
      int matrix[n][m];
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
      }
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            int a = matrix[i][j];
            int b = matrix[n-i-1][j];
            int c = matrix[n-i-1][m-j-1];
            int d = matrix[i][m-j-1];
            vector<int> v = {a,b,c,d};
            sort(v.begin(), v.end());
            int med = v[1];
            for (int i = 0; i < 4; i++)
               ans+= abs(v[i]-med);
            v.clear();
         }
      }
      cout << ans/4 << endl;
   }
}