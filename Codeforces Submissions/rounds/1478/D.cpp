#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int T; cin >> T;
   while (T--) {
      ll n,k; cin >> n >> k;
      ll num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      sort(num, num+n);
      ll gcd = num[1]-num[0];
      for (int i = 1; i < n; i++) {
         gcd  =__gcd(num[i]-num[i-1], gcd);
      }
      bool b = false;
      for (int i = 0; i < n; i++) {
         if ((k-num[i])%gcd == 0)
            b = true;
      }
      if (b)
         cout << "YES" << endl;
      else {
         cout << "NO" << endl;
      }
   }
}