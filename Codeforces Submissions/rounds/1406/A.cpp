#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      int nb[101];
      memset(nb, 0, sizeof nb);
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         nb[x]++;
      }
      int ans = 0;
      for (int i = 0; i <= 100; i++) {
         if (nb[i] == 0) {
            ans = i;
            break;
         }
         else
            nb[i]--;
      }
      for (int i = 0; i <= 100; i++) {
         if (nb[i] == 0) {
            ans+= i;
            break;
         }
      }
      cout << ans << endl;
   }
}