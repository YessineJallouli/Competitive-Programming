#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
   int T; cin >> T;
   while (T--) {
      int v[4];
      int nb = 0;
      int nb1 = 0;
      int nb2 = 0;
      for (int i = 0; i < 4; i++) {
         cin >> v[i];
         if (v[i] % 2 == 0)
            nb++;
         else
            nb1++;
      }
      if (v[0] == 0 || v[1] == 0 || v[2] == 0) {
         if (nb  < 3)
            cout << "No" << '\n';
         else
            cout << "Yes" << '\n';
         continue;
      }
      if (nb == 4 || nb == 3 || nb1 == 4 || nb1 == 3)
         cout << "Yes" << '\n';
      else
         cout << "No" << '\n';
   }

}