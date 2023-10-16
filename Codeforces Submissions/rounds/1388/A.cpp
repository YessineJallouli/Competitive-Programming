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
      /// 6 10 14
      if (n < 31)
         cout << "NO" << '\n';
      else {
         cout << "YES" << '\n';
         if (n == 36)
            cout << "6 10 15 5" << '\n';
         else if (n == 40)
            cout << "6 10 15 9" << '\n';
         else if (n == 44)
            cout << "6 10 15 13" << '\n';
         else
            cout << "6 10 14 " << n-30 << '\n';
      }
   }
}