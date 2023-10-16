#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, k;
      cin >> n >> k;
      if (n%2 == 0) {
         int ans = k%n;
         if(ans == 0) ans = n;
         cout << ans << endl;
         continue;
      }
      int dec = n/2;
      int ans = (k+((k-1)/dec))%n;
      if (ans == 0)
         ans = n;
      cout << ans << endl;
   }
}