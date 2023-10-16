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
      int n,x; cin >> n >> x;
      int a[n];
      int b[n];
      ll ans = 0;
      for (int i = 0; i < n; i++) {
         cin >> a[i]; b[i] = a[i];
         ans+= a[i];
      }
      while (true) {
         bool f = false;
         for (int i = 0; i < n; i++) {
            if (b[i]%x == 0) {
               b[i]/= x;
               ans+= a[i];
            }
            else {
               f = true;
               break;
            }
         }
         if (f)
            break;
      }
      cout << ans << endl;
   }
}