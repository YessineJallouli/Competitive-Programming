/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n,p; cin >> n >> p;
      int a[n];
      vector<pair<int,int>> val(n);
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         val[i] = {a[i], i};
      }
      sort(val.begin(), val.end());
      bool connected[n];
      memset(connected, false, sizeof connected);
      ll ans = 0;
      for (int id = 0; id < n; ++id) {
         int num = val[id].first;
         if (num > p)
            break;
         int i = val[id].second;
         while (i > 0) {
            if (connected[i-1]) break;
            if (a[i-1]%num == 0) {
               ans+= num;
               connected[i-1] = true;
               i--;
            }
            else
               break;
         }
         i = val[id].second;
         while (i < n-1) {
            if (connected[i]) break;
            if (a[i+1]%num == 0) {
               ans+= num;
               connected[i] = true;
               i++;
            }
            else
               break;
         }
      }
      for (int i = 0; i <n-1; i++)
         if (! connected[i])
            ans+= p;
      cout << ans << endl;
   }
}