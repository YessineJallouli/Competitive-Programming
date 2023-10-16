#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k;
      string s; cin >> s;
      int nb = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'L')
            nb++;
      }
      if (nb == n) {
         cout << max(2*k-1,0) << endl;
         continue;
      }
      nb = 0;
      int id = 0;
      vector<pair<int,int>> v;
      for (int i = 0; i < n; i++)
         if (s[i] == 'W') {
            id = i;
            break;
         }
      for (int i = id; i < n; i++) {
         if (s[i] == 'L') {
            nb++;
            continue;
         }
         if (nb > k) {
            nb = 0;
            continue;
         }
         v.push_back({nb, i-nb});
         nb = 0;
      }
      /*if (nb != 0) {
         if (nb <= k && k > 0)
            v.push_back({nb, n-nb});
      }*/
      sort(v.begin(), v.end());
      for (auto i : v) {
         int x = i.first;
         int a = i.second;
         if (k-x < 0)
            break;
         k-= x;
         for (int j = a; j < a+x; j++) {
            s[j] = 'W';
         }
      }
      //cout << s << endl;
      nb = 0;
      int ans = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'W') {
            nb++;
            continue;
         }
         if (nb != 0)
            ans += 2*nb-1;
         nb = 0;
      }
      if (nb != 0)
         ans += 2*nb-1;
      int l = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'L')
            l++;
      }
      k = min(k, l);
      if (k >= 0)
         ans = ans + 2*k;
      cout << ans << endl;
      v.clear();
   }
}