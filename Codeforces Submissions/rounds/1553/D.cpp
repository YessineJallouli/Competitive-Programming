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
      string s, t; cin >> s >> t;
      int n = s.size(), m = t.size();
      if (m > n) {
         cout << "NO" << endl;
         continue;
      }
      bool ans1 = true; bool ans2 = true;
      for (int parity = 0; parity < 2; parity++) {
         int id = -1;
         for (int i = 0; i < n; i++) {
            if (s[i] == t[0] && i%2 == parity) {
               id = i;
               break;
            }
         }
         if (id == -1 && parity == 0) {
            ans1 = false;
            continue;
         }
         if (id == -1 && parity == 1) {
            ans2 = false;
            continue;
         }
         int rem = n-id;
         int del = rem-m;
         if ((del < 0 || del%2 == 1) && parity == 0) {
            ans1 = false;
         }
         if ((del < 0 || del%2 == 1) && parity == 1) {
            ans2 = false;
         }
         int j = 1;
         if (m == j)
            continue;
         int prId = id;
         for (int i = id+1; i < n; i++) {
            if (s[i] == t[j] && (i-prId)%2 == 1) {
               j++;
               prId = i;
            }
            if (j == m)
               break;
         }
         //cout << j << endl;
         if (j != m && parity == 0) {
            ans1 = false;
         }
         if (j != m && parity == 1) {
            ans2 = false;
         }
      }
      if (ans1 || ans2) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}