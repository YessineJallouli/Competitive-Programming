#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      bool tri = true;
      ll nb1 = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         if (num[i] == 1)
            nb1++;
      }
      ll ans = nb1*(nb1-1)/2;
      sort(num, num+n);
      for (ll i = 2; i <= 1e9+1; i*= 2) {
         ll d = i; ll f = i+i-1;
         ll nb = 0;
         for (int j = 0; j < n; j++) {
            if (num[j] >= d && num[j] <= f) {
               nb++;
            }
         }
         ans+= nb*(nb-1)/2;
      }
      cout << ans << endl;
   }
}