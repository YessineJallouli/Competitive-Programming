/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 2e5+7;
vector<vector<int>> graph(mx);
int n,m,k;

bool special[mx];
int dist[mx];

vector<pair<int,int>> D;

void add_edge(int A, int B) {
   graph[A].push_back(B);
   graph[B].push_back(A);
   memset(dist, -1, sizeof dist);
}

int distance_between_two_node(int Start, int End) {
   vector<int> v = {Start};
   dist[Start] = 0;
   if (special[Start]) {
      D.push_back({0,Start});
   }
   int ans = 0;
   bool fnd = false;
   while (! v.empty()) {
      ans++;
      vector<int> v1;
      for (int i : v) {
         for (int j : graph[i]) {
            if (dist[j] != -1)
               continue;
            if (special[j]) {
               D.push_back({ans,j});
            }
            dist[j] = ans;
            v1.push_back(j);
         }
      }
      v.swap(v1);
   }
   return dist[End];
}

int main()
{
   SaveTime
   cin >> n >> m >> k;
   memset(special, false, sizeof special);
   for (int i = 0; i < k; i++) {
      int h; cin >> h;
      special[h] = true;
   }
   for (int i = 0; i < m; i++) {
      int a,b; cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
   }
   memset(dist, -1, sizeof dist);
   int x = distance_between_two_node(1, n);
   sort(D.begin(), D.end());
   int A,B;
   int AnsMin = INT_MAX;
   for (int i = 1; i < D.size(); i++) {
      if (D[i].first-D[i-1].first <= AnsMin) {
         AnsMin = D[i].first-D[i-1].first;
         if (D[i].first >= x && D[i-1].first >= x) {
            A = A = D[i].second; B = D[i-1].second;
            break;
         }
         A = D[i].second; B = D[i-1].second;
      }
   }
   add_edge(A,B);
   int ans1 = distance_between_two_node(1,n);
   graph[A].pop_back();
   graph[B].pop_back();
   add_edge(D[0].second, D.back().second);
   int ans2 = distance_between_two_node(1,n);
   cout << max(ans1, ans2);
}