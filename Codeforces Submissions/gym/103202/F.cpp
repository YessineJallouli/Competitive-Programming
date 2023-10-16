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
   int n; cin >> n;
   vector<pair<int,int>> v(n);
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v[i] = {x,i};
   }
   sort(v.begin(), v.end());
   int pos[n];
   for (int i = 0; i < n; i++) {
      int id = v[i].second;
      pos[i] = id;
   }
   int mx = -1;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      mx = max(mx, pos[i]);
      if (mx == i)
         ans++;
   }
   cout << ans;
}