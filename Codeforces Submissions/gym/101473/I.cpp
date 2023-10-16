#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int N, C, T1, T2; cin >> N >> C >> T1 >> T2;
   if (T1 > T2)
      swap(T1, T2);
   deque<int> q;
   for (int i = 0; i < N; i++) {
      int x; cin >> x;
      q.push_back(x);
   }
   int ans = INT_MAX;
   for (int j = 0; j <= N; j++) {
      int dp[N][2];
      memset(dp, 0, sizeof dp);
      dp[0][0] = T1;
      dp[0][1] = T2;
      for (int i = 1; i < N; i++) {
         int hole = q[i];
         int id1 = lower_bound(q.begin(), q.end(), hole-T1-1) - q.begin();
         if (q[id1] >= hole-T1)
            id1--;
         int id2 = lower_bound(q.begin(), q.end(), hole-T2-1) - q.begin();
         if (q[id2] >= hole-T2)
            id2--;
         if (id1 < 0) {
            dp[i][0] = T1;
         }
         if (id2 < 0) {
            dp[i][1] = T2;
         }
         if (dp[i][0] == 0)
            dp[i][0] = min(dp[id1][0]+T1, dp[id1][1]+T1);
         if (dp[i][1] == 0)
            dp[i][1] = min(dp[id2][0]+T2, dp[id2][1]+T2);
      }
      ans = min({ans, dp[N-1][0], dp[N-1][1]});
      int x = q[0]+C;
      q.pop_front();
      q.push_back(x);
   }
   cout << ans;
}