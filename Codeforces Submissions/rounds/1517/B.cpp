#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      int grid[n][m];
      vector<pair<int,int>> v;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            v.push_back({grid[i][j], i});
         }
      }
      sort(v.begin(), v.end());
      int ans[n][m];
      memset(ans, 0, sizeof ans);
      int id[n];
      memset(id, 0, sizeof id);
      for (int i = 0; i < m; i++) {
         int a = v[i].first;
         int b = v[i].second;
         ans[b][i] = a;
      }
      for (int i = m; i < n*m; i++) {
         int a = v[i].first;
         int ii = v[i].second;
         while (ans[ii][id[ii]] != 0) {
            id[ii]++;
         }
         ans[ii][id[ii]] = a;
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
            cout << ans[i][j] << ' ';
         cout << endl;
      }
   }
}