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
      int n[3];
      for (int i = 0; i < 3; i++)
         cin >> n[i];
      sort(n, n+3);
      if (n[1] == n[2]) {
         cout << "YES" << endl;
         cout << 1 << ' ' << n[0] << ' ' << n[2] << endl;
      }
      else
         cout << "NO" << endl;
   }
}