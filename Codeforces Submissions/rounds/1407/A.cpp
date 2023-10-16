#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int a, b; a = b = 0;
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         if (x == 0)
            a++;
         else
            b++;
      }
      int ans = -1;
      if (a >= n/2) {
         ans = 0;
      }
      else
         ans = 1;
      int k = n/2;
      if (k%2 == 0|| a >= n/2) {
         cout << n/2 << endl;
         for (int i = 0; i < n/2; i++)
            cout << ans << ' ';
         cout << endl;
      }
      else {
         if (b >= n/2+1) {
            cout << n/2+1 << endl;
            for (int i = 0; i < n/2+1; i++)
               cout << 1 << ' ';
            cout << endl;
         }
      }

   }
}