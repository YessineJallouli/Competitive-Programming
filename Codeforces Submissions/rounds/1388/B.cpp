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
      int length = 4*n;
      int nb = ceil(n/4.0);
      for (int i = 0; i < n-nb   ; i++)
         cout << 9;
      for (int i = 0; i < nb; i++)
         cout << 8;
      cout << '\n';
   }
}