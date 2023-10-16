#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   ios_base::sync_with_stdio(false);
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n == 1) {
         cout << 9 << endl;
         continue;
      }
      if (n == 2) {
         cout << 98 << endl;
         continue;
      }
      cout << 989;
      for (int i = 3; i < n; i++) {
         cout << (9+(i-2))%10;
      }
      cout << endl;
   }
}