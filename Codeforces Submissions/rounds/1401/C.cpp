#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n]; int mn = INT_MAX;
      int tri[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         tri[i] = num[i];
         mn = min(num[i], mn);
      }
      sort(tri, tri+n);
      bool ans = true;
      for (int i = 0; i < n; i++) {
         if (num[i] != tri[i]) {
            if (num[i]% mn != 0) {
               ans = false;
            }
         }
      }
      if (! ans) {
         cout << "NO" << '\n';
         continue;
      }
      else
         cout << "YES" << '\n';
   }
}