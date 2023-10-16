#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int n; cin >> n;
   vector<pair<int,int>> v;
   bool infinty = true;
   for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      v.push_back({a,b});
      if (b == 2)
         infinty = false;
   }
   if (infinty) {
      cout << "Infinity";
      return 0;
   }
   ll d =  -1000000000, f = 1000000000;
   bool there = false;
   while (d <= f) {
      bool bb = false;
      ll m = (d+f)/2;
      ll ans = m;
      for (int i = 0; i < n; i++) {
         int a = v[i].first;
         int b = v[i].second;
         if (b == 1 && ans < 1900) {
            d = m+1;
            bb = true;
            break;
         }
         if (b == 2 && ans >= 1900) {
            f = m-1;
            bb = true;
            break;
         }
         ans+= a;
      }
      if (bb)
         continue;
      d = m;
      there = true;
      if (f-d == 1)
         d = f;
      if (d == f)
      {
         bool hh = true;
         int aa = d;
         for (int i = 0; i < n; i++) {
            int k = v[i].first;
            int s = v[i].second;
            if (aa >= 1900 && s == 2)
               hh = false;
            if (aa < 1900 && s == 1)
               hh = false;
            aa+= k;
         }
         if (hh)
           cout << aa;
         else
            cout << aa-1;
         break;
      }
   }
   if (!there)
      cout << "Impossible";
}