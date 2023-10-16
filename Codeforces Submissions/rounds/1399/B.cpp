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
      int a[n], b[n];
      int mina = INT_MAX;
      int minb = INT_MAX;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (a[i] < mina)
            mina = a[i];
      }
      for (int i = 0; i < n; i++) {
         cin >> b[i];
         minb = min(minb, b[i]);
      }
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         int d = max(b[i]-minb, a[i]-mina);
         ans+=d;
      }
      cout << ans << '\n';
   }
}