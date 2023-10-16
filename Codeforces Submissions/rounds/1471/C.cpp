/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      int k[n], present[m];
      for (int i = 0; i < n; i++)
         cin >> k[i];
      sort(k, k+n);
      reverse(k, k+n);
      for (int i = 0; i < m; i++)
         cin >> present[i];
      int idx = 0;
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         if(idx > k[i]-1) ans+=present[k[i]-1];
         else {
            ans +=present[idx];
            idx++;
         }
      }
      cout << ans << endl;
   }
}