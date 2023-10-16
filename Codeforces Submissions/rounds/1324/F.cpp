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
vector<vector<int>> tree(mx);
int color[mx];
int ans[mx];
int dp[mx];

void dfs1(int v, int par = -1) {
   dp[v] = color[v];
   for (int ch : tree[v]) {
      if (ch == par) continue;
      dfs1(ch, v);
      dp[v]+= max(0, dp[ch]);
   }
}

void dfs2(int v, int par = -1) {
   ans[v] = dp[v];
   for (int ch : tree[v]) {
      if (ch == par) continue;
      dp[v]-= max(dp[ch],0);
      dp[ch]+= max(dp[v], 0);
      dfs2(ch, v);
      dp[ch]-= max(dp[v], 0);
      dp[v]+= max(dp[ch],0);
   }
}

int main()
{
   SaveTime
   int n; cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> color[i+1];
      if (color[i+1] == 0)
         color[i+1] = -1;
   }
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   dfs1(1);
   dfs2(1);
   for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
   }
}