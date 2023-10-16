/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 1e5+7;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int a[n], b[n];
      int posI[mx] = {}, posP[mx] = {};
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         b[i] = a[i];
      }
      sort(b, b+n);
      for (int i = 0; i < n; i++) {
         if (i%2)
            posI[b[i]]++;
         else
            posP[b[i]]++;
      }
      bool ans = true;
      for (int i = 0; i < n; i++) {
         if (i%2) {
            if (posI[a[i]] > 0) {
               posI[a[i]]--;
            }
            else
               ans = false;
         }
         else  {
            if (posP[a[i]] > 0) {
               posP[a[i]]--;
            }
            else
               ans = false;
         }
      }
      if (ans)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';
   }
}