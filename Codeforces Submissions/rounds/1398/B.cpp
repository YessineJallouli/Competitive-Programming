#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n = (int) s.length();
      vector<int> v;
      int nb = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '1')
         {
            nb++;
            continue;
         }
         v.push_back(nb);
         nb = 0;
      }
      v.push_back(nb);
      sort(v.rbegin(), v.rend());
      int ans = 0;
      for (int i = 0; i < v.size(); i++) {
         if (i%2 == 0)
            ans+= v[i];
      }
      cout << ans << endl;
   }
}