#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int delta[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, m; cin >> n >> m;
      char grid[n][m];
      int G = 0, B = 0;
      for (int i = 0; i < n; i++) {
         string s; cin >>s;
         for (int j = 0; j < m; j++)
         {
            grid[i][j] = s[j];
            if (grid[i][j] == 'G')
               G++;
            else if (grid[i][j] == 'B')
               B++;
         }
      }
      if (G == 0) {
         cout << "YES" << '\n';
         continue;
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
               for (int t = 0; t < 4; t++) {
                  int depY = delta[t][0]+i;
                  int depX = delta[t][1]+j;
                  if (depY >= 0 && depY < n && depX >= 0 && depX < m)
                     if (grid[depY][depX] == '.')
                        grid[depY][depX] = '#';
               }
            }
         }
      }
      /*for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
            cout << grid[i][j];
         cout << endl;
      }*/
      vector<pair<int,int>> v;
      v.push_back({n-1, m-1});
      vector<pair<int,int>> transit;
      int affected[n][m];
      bool ans = true;
      memset(affected, -1, sizeof affected);
      int visited[n][m];
      memset(visited, -1, sizeof visited);
      while (true) {
         if (v.size() == 0)
            break;
         for (auto T : v) {
            int Y = T.first, X = T.second;
            for (int t = 0; t < 4; t++) {
               int depY = delta[t][0]+Y;
               int depX = delta[t][1]+X;
               if (depY >= 0 && depY < n && depX >= 0 && depX < m)
                  if (grid[depY][depX] != '#' && visited[depY][depX] == -1) {
                     visited[depY][depX] = 1;
                     if (grid[depY][depX] == 'B')
                        ans = false;
                     else if (grid[depY][depX] == 'G') {
                        affected[depY][depX] = 1;
                     }
                     transit.push_back({depY, depX});
                  }
            }
         }
         v = transit;
         transit.clear();
      }
      int nb = 0;
      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            if (affected[i][j] == 1)
               nb++;
      if (nb != G || ! ans)
         cout << "NO" << '\n';
      else
         cout << "YES" << '\n';
   }
}