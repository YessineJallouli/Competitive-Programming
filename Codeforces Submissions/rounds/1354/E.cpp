/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 5e3+7;
int color[mx];

vector<pair<int,int>> partition_len;
vector<pair<vector<int>, vector<int>>> subgraph;

bool isBipartite(vector<vector<int>> &graph) {
   int NB = graph.size();
   for (int i = 0; i < NB; i++) {
      if (color[i] != -1)
         continue;
      vector<int> v1; vector<int> v2;
      int nb1 = 0, nb2 = 0;
      int cl = 0;
      vector<int> b = {i};
      while (!b.empty()) {
         for (int v : b) {
            if (cl && color[v] == -1) {
               v1.push_back(v);
               nb1++;
            }
            else if (color[v] == -1) {
               v2.push_back(v);
               nb2++;
            }
            color[v] = cl;
         }
         vector<int> aux;
         for (int v : b) {
            for (int ch : graph[v]) {
               if (color[ch] == -1)
                  aux.push_back(ch);
               else if (color[ch] == color[v])
                  return false;
            }
         }
         cl^= 1;
         b.clear();
         b.swap(aux);
      }
      partition_len.push_back({nb1, nb2});
      subgraph.push_back({v1,v2});
   }
   return true;
}

int n2;

int dp[mx][mx];

bool possible_sum(int id = 0, int sum = 0) {
   if (sum > n2)
      return false;
   if (id == partition_len.size()) {
      return dp[id][sum] = (sum == n2);
   }
   if (dp[id][sum] != -1)
      return dp[id][sum];
   return dp[id][sum] = (possible_sum(id+1, sum+partition_len[id].first) || possible_sum(id+1, sum+partition_len[id].second));
}

int main()
{
   SaveTime
   memset(dp, -1, sizeof dp);
   int n,m; cin >> n >> m;
   vector<int> v(3);
   for (int i = 0; i < 3; i++) {
      cin >> v[i];
   }
   n2 = v[1];
   vector<vector<int>> graph(n);
   for (int i = 0; i < m; i++) {
      int a,b; cin >> a >> b; a--; b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   memset(color, -1, sizeof color);
   if (! isBipartite(graph)) {
      cout << "NO";
   }
   else {
      if (possible_sum()) {
         cout << "YES" << endl;
         memset(color, -1, sizeof color);
         int sum = 0;
         for (int i = 0; i < subgraph.size(); i++) {
            if (dp[i+1][sum+partition_len[i].first] == 1) {
               sum+= partition_len[i].first;
               for (int j = 0; j < subgraph[i].first.size(); j++) {
                  int x = subgraph[i].first[j];
                  color[x] = 2;
               }
            }
            else {
               sum+= partition_len[i].second;
               for (int j = 0; j < subgraph[i].second.size(); j++) {
                  int x = subgraph[i].second[j];
                  color[x] = 2;
               }
            }
         }
         int cnt = 0;
         for (int i = 0; i < n; i++) {
            if (color[i] == 2)
               continue;
            if (cnt == v[0])
               color[i] = 3;
            else {
               color[i] = 1;
               cnt++;
            }
         }
         for (int i = 0; i < n; i++)
            cout << color[i];
      }
      else {
         cout << "NO";
      }
   }
}