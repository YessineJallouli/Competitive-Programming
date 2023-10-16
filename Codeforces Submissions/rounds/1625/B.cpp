#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;
int prv[N];

int main() {
    SaveTime
   int T; cin >> T;
   while (T--) {
       int n; cin >> n;
       set<int> s;
       int a[n];
       for (int i = 0; i < n; i++) {
           cin >> a[i];
           s.insert(a[i]);
       }
       for (int i : s)
           prv[i] = -1;
       int ans = 0;
       for (int i = 0; i < n; i++) {
           int id = prv[a[i]];
           if (id == -1) {
               prv[a[i]] = i;
               continue;
           }
           int pos = id+1;
           int ex = n-i-1;
           ans = max(ans, ex+pos);
           prv[a[i]] = i;
       }
       if (ans == 0)
           cout << -1 << '\n';
       else
          cout << ans << '\n';
   }
}