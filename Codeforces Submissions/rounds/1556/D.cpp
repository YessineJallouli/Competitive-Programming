/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int mx = 1e9+7;


int main() {
   int n, k; cin >> n >> k;
   int ad[n];
   int ou[n];
   for (int i = 1; i < n; i++) {
      cout << "and 1 " << i+1 << endl;
      cin >> ad[i];
      cout << "or 1 " << i+1 << endl;
      cin >> ou[i];
   }
   int one = 0;
   int visite[31];
   memset(visite, -1, sizeof visite);
   for (int i = 1; i < n; i++) {
      int x = ad[i], y = ou[i];
      for (int j = 0; (1 << j) < mx; j++) {
         int bit1 = (x & (1 << j)) > 0;
         int bit2 = (y & (1 << j)) > 0;
         if (bit1 == 0 && bit2 == 0) {
            visite[j] = 0;
         }
         else if (bit1 == 1 && bit2 == 1 && visite[j] == -1) {
            visite[j] = 1;
            one+= (1<<j);
         }
      }
   }
   cout << "and 2 3\n";
   int x; cin >> x;
   cout << "or 2 3\n";
   int y; cin >> y;
   for (int i = 0; (1 << i) < mx; i++) {
      if (visite[i] != -1)
         continue;
      int bit1 = (x & (1 << i)) > 0;
      int bit2 = (y & (1 << i)) > 0;
      visite[i] = (bit1^1);
      int bt = bit1^1;
      one+= (bt<<i);
   }
   int guess[n];
   guess[0] = one;
   for (int i = 1; i < n;i++) {
      int x = ad[i], y = ou[i];
      int ans = 0;
      for (int j = 0; (1 << j) < mx; j++) {
         int bit1 = (x & (1 << j)) > 0;
         int bit2 = (y & (1 << j)) > 0;
         int bit3 = (one & (1 << j)) > 0;
         if (bit3 == 0) {
            if (bit2 == 1)
               ans+= (1 << j);
         }
         else if (bit3 == 1) {
            if (bit1 == 1) {
               ans+= (1 << j);
            }
         }
      }
      guess[i] = ans;
   }
   sort(guess, guess+n);
   cout << "finish " << guess[k-1];
}