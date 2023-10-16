/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 1e3+7;
vector<vector<pair<int,pair<int,int>>>> graph(mx);
int n,m;

bool seen[mx];

bool solve(int node, int L, int R) {
   if (node == n)
      return true;
   seen[node] = true;
   bool ans = false;
   for (auto i : graph[node]) {
      int ch = i.first;
      if (seen[ch])
         continue;
      int l = i.second.first;
      int r = i.second.second;
      if (l <= L && r >= R) {
         ans = ans|solve(ch, L, R);
      }
   }
   return ans;
}

int main() {
   SaveTime
   cin >> n >> m;
   int left[m], right[m];
   for (int i = 0; i < m; i++) {
      int a,b,l,r; cin >> a >> b >> l >> r;
      graph[a].push_back({b,{l,r}});
      graph[b].push_back({a,{l,r}});
      left[i] = l;
      right[i] = r;
   }
   int ans = 0;
   for (int i = 0; i < m; i++) {
      int L = left[i];
      int d = L, f = right[i];
      while (d <= f) {
         int R = (d+f)/2;
         memset(seen,false, sizeof seen);
         if (solve(1,L,R)) {
            ans = max(ans, R-L+1);
            d = R+1;
         }
         else
            f = R-1;
      }
   }
   if (ans == 0) {
      cout << "Nice work, Dima!";
   }
   else
      cout <<  ans;
}