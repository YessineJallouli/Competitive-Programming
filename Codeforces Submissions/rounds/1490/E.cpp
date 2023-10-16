/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      pair<int,int> a[n];
      for (int i = 0; i < n ;i++) {
         int x; cin >> x;
         a[i] = {i+1, x};
      }
      sort(a, a+n, [&] (pair<int,int> a, pair<int,int> b) {return a.second < b.second;});
      ll prefixsum = 0;
      vector<int> ans;
      for (int i = 0; i < n-1; i++) {
         prefixsum+= a[i].second;
         if (prefixsum >= a[i+1].second)
            ans.push_back(a[i].first);
         else
            ans.clear();
      }
      ans.push_back(a[n-1].first);
      cout << ans.size() << endl;
      sort(ans.begin(), ans.end());
      for (int i: ans)
         cout << i << ' ';
      cout << endl;
   }
}