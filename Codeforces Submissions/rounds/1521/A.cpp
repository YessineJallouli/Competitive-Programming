#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll A, B; cin >> A >> B;
      if (B == 1) {
         cout << "NO" << endl;
         continue;
      }
      ll x = A*B, y = x-A, z = x-y;
      if (y != z) {
         cout << "YES" << endl;
         cout << y << ' ' << z << ' ' << x << endl;
      }
      else {
         ll p = 3;
         while (__gcd(A,p) != 1)
            p++;
         cout << "YES" << endl;
         cout << A*A << ' ' << p*A << ' ' << A*(p+A) << endl;
      }
   }
}