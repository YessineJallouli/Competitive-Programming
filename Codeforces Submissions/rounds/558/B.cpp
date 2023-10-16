#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; cin >> n;
   map<int,int> m;
   int num[n];
   int mx = 0;
   for (int i = 0; i < n; i++) {
      cin >> num[i];
      m[num[i]]++;
      mx = max(mx, m[num[i]]);
   }
   map<int,int> d;
   map<int,int> f;
   for (int i = 0; i < n; i++) {
      if (i != 0 && d[num[i]] == 0 && num[0] != num[i])
         d[num[i]] = i;
      f[num[i]] = max(f[num[i]], i);
   }
   int D = -1,F = -1;
   int mn = INT_MAX;
   for (int i = 0; i < n; i++) {
      if (m[num[i]] == mx) {
         if (mn > f[num[i]]-d[num[i]]) {
            mn = f[num[i]]-d[num[i]];
            D = d[num[i]];
            F = f[num[i]];
         }
      }
   }
   cout << D+1 << ' ' << F+1;
}