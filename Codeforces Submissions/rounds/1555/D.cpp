/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   string ch[6] = {"abc","acb","bac","bca", "cab", "cba"};
   int n,m; cin >> n >> m;
   int pr[6][n+1];
   string s; cin >> s;
   for (int j = 0; j < 6; j++) {
      int num[n];
      memset(num, 0, sizeof num);
      for (int i=0;i<n; i++) {
         if (s[i] != ch[j][i%3]) {
            num[i]++;
         }
      }
      pr[j][0] = 0;
      for (int i = 0; i < n; i++) {
         pr[j][i+1] = pr[j][i] + num[i];
      }
   }
   while (m--) {
      int a,b; cin >> a >> b; a--; b--;
      int ans = n+1;
      for (int i = 0; i < 6; i++)
         ans = min(ans, pr[i][b+1]-pr[i][a]);
      cout << ans << '\n';
   }
}