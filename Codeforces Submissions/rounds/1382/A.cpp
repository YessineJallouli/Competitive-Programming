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
   int t; cin >> t;
   while (t--) {
      int n, m;
      cin >> n >> m;
      map<int,int> num;
      for (int i = 0; i < n; i++)
      {
         int x; cin >> x;
         num[x] = true;
      }
      bool b = true;
      for (int i = 0; i < m; i++) {
         int x; cin >> x;
         if (num[x] && b)
         {
            cout << "YES" << '\n';
            cout << 1 << ' ' << x << '\n';
            b = false;
         }
      }
      if(b)
         cout << "NO" << '\n';
      num.clear();
   }
}