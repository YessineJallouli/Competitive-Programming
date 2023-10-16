#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int x; cin >> x;
      int num[n];
      int even, odd;
      even = odd = 0;
      for (int i = 0; i < n; i++)
      {
         int h; cin >> h;
         if (h%2 == 0)
            even++;
         else
            odd++;
      }
      if (x == n && odd%2 == 0) {
         cout << "no" << endl;
      }
      else if (odd == 0) {
         cout << "no" << endl;
      }
      else if (even == 0 && x%2 == 0)
         cout << "no" << endl;
      else
         cout << "yes" << endl;
   }
}