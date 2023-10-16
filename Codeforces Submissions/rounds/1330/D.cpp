#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   cout.flush();
   int T; cin >> T;
   while (T--) {
      int d, m; cin >> d >> m;
      ll ans = 1;
      for (int i = 0; i < 30; i++)
      {
         if (1 << i <= d && 1 << i+1 > d)
         {
              ans = (ans * (d - (1 << i) + 2)) % m;
              break;
         }
         else
            ans = (ans * ((1 << i) + 1)) % m;
      }
      cout << (int) (ans-1+m)%m << endl;
   }
}