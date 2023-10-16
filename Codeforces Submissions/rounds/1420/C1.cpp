#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n, q; cin >> n >> q;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      bool asc = true;
      ll ans = 0;
      for (int i = 0; i < n-1; i++) {
         if (num[i] <= num[i+1] && asc)
            continue;
         if (num[i] >= num[i+1] && !asc) {
            continue;
         }
         if (asc) {
            ans+= num[i];
            asc = false;
         }
         else if (!asc) {
            if (i == n-2 && num[i] >= num[i+1])
               continue;
            ans-= num[i];
            asc = true;
         }
      }
      if (asc)
         ans+= num[n-1];
      cout << ans << endl;
   }
}