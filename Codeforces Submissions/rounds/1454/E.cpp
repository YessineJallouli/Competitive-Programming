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

deque<int> v;
deque<int> cycle;
bool visite[mx];
bool cyclic[mx];
bool b = true;

int inter;

void findthecycle(int node) {
   //cout << node << endl;
   v.push_back(node);
   visite[node] = true;
   for (int i : graph[node]) {
      if (visite[i]) {
         if (v.size() > 1) {
            int n = v.size()-2;
            if (v[n] == i)
               continue;
            else if (b) {
               //cycle detected for the first time
               inter = i;
               b = false;
               while (v[0] != i && v.size() != 0) {
                  v.pop_front();
               }
               for (int j : v) {
                  cycle.push_back(j);
               }
            }
         }
         else {
            continue;
         }
      }
      else
         findthecycle(i);
   }
   if (v.size() != 0)
      v.pop_back();
   visite[node] = false;
}

ll bfs(int node) {
   if (visite[node]) {
      visite[node] = false;
      return 0;
   }
   visite[node] = true;
   ll ans = 1;
   for (int i : graph[node]) {
      if (visite[i] || cyclic[i])
         continue;
      ans = ans + bfs(i);
   }
   visite[node] = false;
   return ans;
}

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      v.clear();
      cycle.clear();
      b = true;
      ll n; cin >> n;
      for (int i = 0; i < n; i++) {
         int a,b; cin >> a >> b;
         graph[a].push_back(b);
         graph[b].push_back(a);
      }
      memset(visite, false, sizeof visite);
      findthecycle(n);
      memset(cyclic, false, sizeof cyclic);
      for (int i : cycle)
         cyclic[i] = true;
      ll ans = n*(n-1)/2;
      ll nb = cycle.size();
      ll cnt = 0;
      for (int i : cycle) {
         //memset(visite, false, sizeof visite);
         ll x = bfs(i)-1;
         if (x == 0)
            continue;
         cnt+= (n-nb-x)*x;
         ans+= x*(nb-1);
      }
      for (int i = 0; i <= n; i++) {
         graph[i].clear();
      }
      cout << ans+cnt/2+ (nb*(nb-1))/2 << endl;
   }
}