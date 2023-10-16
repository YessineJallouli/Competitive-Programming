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
      int n;
      cin >> n;
      int a[n], b[n];
      int s[n];
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         s[i] = a[i];
      }
      for (int i = 0; i < n; i++)
         cin >> b[i];
      sort(s, s+n);
      bool ans = true;
      for (int i = 0; i < n; i++) {
         if (s[i] != a[i])
            ans = false;
      }
      bool o, z;
      o = z = false;
      for (int i = 0; i < n; i++) {
         if (b[i] == 0)
            z = true;
         else
            o = true;
      }
      bool t = z&o;
      if (ans || t)
         cout << "Yes" << '\n';
      else
         cout << "No" << '\n';
   }
}