#include<bits/stdc++.h>
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k;
      if (k < n) {
         int a = n/k;
         if (n%k) a++;
         k = (a)*k;
      }
      int ans = k/n;
      if (k%n)
         ans++;
      cout << ans << endl;
   }
}