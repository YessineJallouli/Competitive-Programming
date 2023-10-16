#include "bits/stdc++.h"
using namespace std;
// Hi

int main(){
   ios::sync_with_stdio(0);cin.tie(0);
   int tt;
   cin>>tt;
   while(tt--){
      int n; cin >> n;
      int ans = 0;
      long long x = 1;
      while (x <= n) {
         for (int i = 1; i < 10; i++) {
            if (x*i <= n) {
               ans++;
            }
            else
               break;
         }
         x = x*10+1;
      }
      cout << ans << endl;
   }

   return 0;
}