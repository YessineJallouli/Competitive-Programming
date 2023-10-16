/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

const int mx = 2e5+7;
vector<int> color(mx, -1);

bool Bipartition(vector<vector<int>>& graph) {
   int n = graph.size();
   for (int i = 0; i < n; i++) {
      if (color[i] != -1)
         continue;
      vector<int> b = {i};
      int cl = 0;
      while(! b.empty()) {
         cl^= 1;
         vector<int> aux;
         for (int v : b) {
            color[v] = cl;
            for (int child : graph[v]) {
               if (color[child] == -1) {
                  aux.push_back(child);
               }
               else if (color[child] == color[v])
                  return false;
            }
         }
         aux.swap(b);
      }
   }
   return true;
}

int main() {
   SaveTime
   int T; cin >> T;
      while (T--) {
      int n,m; cin >> n >> m;
      vector<vector<int>> graph(n);
      int a[n], b[n];
      ll s = 0;
      for (int i = 0; i < n; i++) {
         cin >> a[i]; s = (s + abs(a[i]))%2;
      }
      for (int i = 0; i < n; i++) {
         cin >> b[i]; s = (s + abs(b[i]))%2;
      }
      for (int i = 0; i < m; i++) {
         int x,y; cin >> x >> y; x--; y--;
         graph[x].push_back(y);
         graph[y].push_back(x);
      }
      color.assign(n,-1);
      if (s%2 == 1)
         cout << "NO" << endl;
      else if (! Bipartition(graph))
         cout << "YES" << endl;
      else {
         ll sum = 0;
         for (int i = 0; i < n; i++) {
            if (color[i] == 0)
               sum+= a[i]-b[i];
            else
               sum-= a[i]-b[i];
         }
         if (sum == 0)
            cout << "YES" << endl;
         else
            cout << "NO" << endl;
      }
   }
}