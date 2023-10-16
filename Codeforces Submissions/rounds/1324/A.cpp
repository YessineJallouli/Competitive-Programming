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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      bool p = false, ip = false;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         if (num[i] % 2 == 0)
            p = true;
         else
            ip = true;
      }
      if (p && ip)
         cout << "NO" << endl;
      else
         cout << "YES" << endl;

   }
}