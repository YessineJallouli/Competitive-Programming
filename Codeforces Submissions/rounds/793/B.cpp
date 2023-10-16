#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int n,m; cin >> n >> m;
   char grid[n][m];
   int si, sj;
   int ei, ej;
   for (int i = 0; i < n; i++) {
      string s; cin >> s;
      for (int j = 0; j < m; j++) {
         grid[i][j] = s[j];
         if (grid[i][j] == 'S') {
            si = i; sj = j;
         }
         if (grid[i][j] == 'T') {
            ei = i; ej = j;
         }
      }
   }
   int nb[n][m];
   memset(nb, -1, sizeof nb);
   int cnt = -1;
   int delta[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
   vector<pair<int,int>> v = {{si, sj}};
   while (! v.empty()) {
      vector<pair<int,int>> aux;
      for (auto ch : v) {
         int I = ch.first;
         int J = ch.second;
         nb[I][J] = max(cnt,0);
         for (int t = 0; t < 4; t++) {
            int i = I, j = J;
            while (true) {
               i+= delta[t][0];
               j+= delta[t][1];
               if (i < 0 || j < 0 || i == n || j == m)
                  break;
               if (nb[i][j] != -1)
                  continue;
               if (grid[i][j] != '*') {
                  aux.push_back({i, j});
                  nb[i][j] = cnt+1;
               }
               else
                  break;
            }
         }
      }
      v.swap(aux);
      cnt++;
      if (cnt == 2)
         break;
   }
   if (nb[ei][ej] == -1 || nb[ei][ej] > 2) {
      cout << "NO";
   }
   else {
      cout << "YES";
   }
}