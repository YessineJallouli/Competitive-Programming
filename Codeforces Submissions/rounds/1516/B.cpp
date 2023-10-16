#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int Px[n+1];
      int Sx[n+1];
      Px[0] = 0;
      Sx[n] = 0;
      for (int i = 0; i < n; i++) {
         Px[i+1] = Px[i]^num[i];
      }
      for (int i = n-1; i >= 0; i--) {
         Sx[i] = Sx[i+1]^num[i];
      }
      int all = Px[n];
      bool ans = false;
      if (all == 0)
         ans = true;
      for (int i = 0; i < n; i++) {
         int nb1 = Px[i+1];
         for (int j = i+2; j < n; j++) {
            int nb2 = Sx[j];
            int nb3 = all^nb2^nb1;
            if (nb1 == nb2 && nb2 == nb3) {
               ans = true;
            }
         }
      }
      if (ans)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}