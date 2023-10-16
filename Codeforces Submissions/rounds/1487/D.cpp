#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int ans2 = 0;
      for (int a = 1; a*a <= 2*n+1; a++) {
         int c = a*a+1;
         if (a%2 == 0)
            continue;
         c/= 2;
         int b = c-1;
         if (c >= b && c <= n && b >= a) {
            ans2++;
         }
      }
      cout << ans2 << endl;
   }
}