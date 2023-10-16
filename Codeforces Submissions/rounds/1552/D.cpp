/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool solve(const vector<int> &v, int id = 0, int sum1 = 0, int sum2 = 0, int took = 0) {
   if (sum1 == sum2 && took != 0) {
      //cout << sum1 << ' ' << sum2 << endl;
      return true;
   }
   if (id == v.size())
      return false;
   return (solve(v, id+1, sum1+v[id], sum2, took+1) || solve(v, id+1, sum1, sum2+v[id], took+1) || solve(v, id+1, sum1, sum2, took));
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      vector<int> v;
      bool ans = false;

      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         v.push_back(x);
         if (x == 0)
            ans = true;
      }
      if (ans) {
         cout << "YES" << "\n";
         continue;
      }
      if (solve(v)) {
         cout << "YES" << "\n";
      }
      else
         cout << "NO" << "\n";
   }
}