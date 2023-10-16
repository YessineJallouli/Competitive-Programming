/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool intersection(int x1, int y1, int x2, int y2, int n) {
   map<int,bool> m;
   if (x1 > y1)
      swap(x1, y1);
   if (((x2 > 0 && x2 < x1) || (x2 > y1 && x2 <= n)) && ((y2 > 0 && y2 < x1) || (y2 > y1 && y2 <= n)))
      return false;
   if ((x2 > x1 && x2 < y1) && (y2 > x1 && y2 < y1))
      return false;
   return true;
}
int n;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int k; cin >> n >> k;
      vector<pair<int,int>> v;
      bool used[2*n+1];
      memset(used, false, sizeof used);
      for (int i = 0; i < k; i++) {
         int a,b; cin >> a >> b;
         used[a] = true;
         used[b] = true;
         v.push_back({a,b});
      }
      vector<int> unused;
      for (int i = 1; i <= 2*n; i++) {
         if (! used[i])
            unused.push_back(i);
      }
      for (int i = 0; i < n-k; i++) {
         v.push_back({unused[i], unused[i+n-k]});
      }
      int ans = 0;
      for (int i = 0; i < v.size(); i++) {
         for (int j = i+1; j < v.size(); j++) {
            int x1 = v[i].first;
            int x2 = v[j].first;
            int y1 = v[i].second;
            int y2 = v[j].second;
            if (intersection(x1,y1,x2,y2,2*n)) {
               ans++;
            }
         }
      }
      cout << ans << endl;
   }
}