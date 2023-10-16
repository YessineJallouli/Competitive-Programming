#include "bits/stdc++.h"
using namespace std;


void query(int a, int b) {
   cout << "?" << ' ' << a << ' ' << b << endl;
   cout.flush();
}

int main(){
   int n, t; cin >> n >> t;
   int memo[n+1];
   memset(memo, -1, sizeof memo);
   while (t--) {
      int k; cin >> k;
      int d = 1, f = n;
      int ans;
      while (d <= f) {
         int mid = (f+d)/2;
         int x;
         if (memo[mid] != -1)
            x = memo[mid];
         else {
            query(1,mid);
            cin >> x;
            memo[mid] = x;
         }
         if (mid-x < k) {
            d = mid+1;
         }
         else {
            f = mid-1;
            ans = mid;
         }
      }
      cout << "! " << ans << endl;
      cout.flush();
      for (int i = ans; i <= n; i++)
         if (memo[i] != -1)
            memo[i]++;
   }
   return 0;
}