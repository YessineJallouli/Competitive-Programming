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
int weight[mx];
ll sum[mx];
ll dp[mx];
ll ans[mx];

vector<vector<int>> tree(mx);

ll total = 0;

ll sumofsubtree(int v, int pr = -1) {
   sum[v] = weight[v];
   for (int ch : tree[v]) {
      if (ch == pr) continue;
      sum[v]+= sumofsubtree(ch, v);
   }
   return sum[v];
}

void dfs1(int v, int pr = -1) {
   dp[v] = 0;
   for (int ch : tree[v]) {
      if (ch == pr) continue;
      dfs1(ch, v);
      dp[v]+= dp[ch]+ sum[ch];
   }
}

void dfs2(int v, int pr = -1) {
   for (int ch : tree[v]) {
      if (ch == pr) continue;
      dp[ch] = dp[v]+total-2*sum[ch];
      dfs2(ch, v);
   }
}


int main()
{
   int n; cin >> n;
   for (int i = 1; i <= n; i++) {
      cin >> weight[i];
      total+= weight[i];
   }
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   memset(dp, 0, sizeof dp);
   sumofsubtree(1);
   dfs1(1);
   dfs2(1);
   ll res = 0;
   for (int i = 1; i <= n; i++) {
      res = max(res, dp[i]);
   }
   cout << res;
}