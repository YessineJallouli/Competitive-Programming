#include <bits/stdc++.h>
#define ll long long
using namespace std;

int sort_permutation_with_swap(vector<int> p) {
   int N = p.size();
   int visite[N+1];
   memset(visite, false, sizeof visite);
   int ans = 0;
   for (int i = 0; i < N; i++) {
      if (p[i] == i+1)
         continue;
      if (visite[p[i]])
         continue;
      int sizeofcycle = 0;
      int x = p[i];
      while (!visite[x]) {
         visite[x] = true;
         x = p[x-1];
         sizeofcycle++;
      }
      ans+=(sizeofcycle-1);
   }
   return ans;
}

int main() {
   int n,m; cin >> n >> m;
   int grid[n][m];
   int x,y;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> grid[i][j];
         if (grid[i][j] == 1) {
            y = i;
            x = j;
         }
      }
   }
   bool ans = true;
   for (int i = 0; i < n; i++) {
      vector<int> v;
      for(int j = 0; j < m; j++) {
         v.push_back(grid[i][j]);
      }
      sort(v.begin(), v.end());
      for (int j = 0; j < m; j++) {
         if (v[j]-v[0] != j)
            ans = false;
      }
   }
   for (int i = 0; i < m; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
         v.push_back(grid[j][i]);
      }
      sort(v.begin(), v.end());
      for (int j = 0; j < n; j++) {
         if ((v[j]-v[0])%m) {
            ans = false;
         }
      }
   }
   if (! ans) {
      cout << '*';
      return 0;
   }
   vector<int> p1;
   for (int i = 0; i < m; i++)
      p1.push_back(grid[y][i]);
   vector<pair<int,int>> p;
   for (int i = 0; i < n; i++)
      p.push_back({grid[i][x],i+1});
   sort(p.begin(), p.end());
   vector<int> p2;
   for (int i = 0; i < n; i++)
      p2.push_back(p[i].second);
   cout << sort_permutation_with_swap(p1)+ sort_permutation_with_swap(p2);
}