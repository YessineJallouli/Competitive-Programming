#include <bits/stdc++.h>
using namespace std;

int main() {

	int T;
	cin >> T;
	while (T--) {
      int n,m,x; cin >> n >> m >> x;
      cout << "YES" << endl;
      vector<pair<int,int>> v;
      for (int i = 0; i < n; i++) {
         int a; cin >> a;
         v.push_back({a, i});
      }
      sort(v.rbegin(), v.rend());
      int ans[n];
      for (int i = 0; i < n; i++) {
         int id = v[i].second;
         ans[id] = (i%m)+1;
      }
      for (int i = 0; i < n; i++)
         cout << ans[i] << ' ';
      cout << endl;
   }
}