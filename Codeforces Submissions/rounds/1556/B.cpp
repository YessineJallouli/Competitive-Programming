/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      int nbO = 0, nbZ = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         num[i]%= 2;
      }
      for (int i = 0; i < n; i++) {
         if (num[i])
            nbO++;
         else
            nbZ++;
      }
      if (abs(nbO-nbZ) > 1) {
         cout << -1 << '\n';
         continue;
      }
      if (nbZ > nbO) {
         for (int i = 0; i < n; i++) {
            num[i]^= 1;
         }
         swap(nbZ, nbO);
      }
      vector<int> posO;
      for (int i = 0; i < n; i++) {
         if (num[i] == 1)
            posO.push_back(i);
      }
      int ans1 = 0;
      int ans2 = 0;
      if (nbZ == nbO) {
         for (int i = 0; i < n; i+= 2) {
            ans1+= abs(posO[i/2]-i);
         }
         for (int i = 1; i < n; i+= 2) {
            ans2+= abs(posO[i/2]-i);
         }
         cout << min(ans1, ans2) << '\n';
      }
      else {
         for (int i = 0; i < n; i+= 2) {
            ans1+= abs(posO[i/2]-i);
         }
         cout << ans1 << '\n';
      }
   }
}