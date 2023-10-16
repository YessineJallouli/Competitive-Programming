#include <bits/stdc++.h>

using namespace std;

int main()
{

   int T; cin >> T;
   for (int ii = 0; ii < T; ii++) {
      int n,k; cin >> n >> k;
      int a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      if (k == 1 && a[0] != a[n-1]) {
         cout << -1 << endl;
         continue;
      }
      if (k == 1 && a[0] == a[n-1]) {
         cout << 1 << endl;
         continue;
      }
      int b[101];
      int m = 1;
      int distinct = k+1;
      while (distinct > k) {
         distinct = 1;
         int pr = a[0];
         for (int i = 0; i < n; i++) {
            if (a[i] != pr)
               distinct++;
            if (distinct <= k) {
               b[i] = a[i];
               pr = a[i];
               a[i] = 0;
            }
            else {
               if (a[n-1] == 0)
                  break;
               m++;
               for (int j = i; j < n; j++) {
                  b[j] = b[i-1];
                  a[j]-= b[i-1];
               }
               break;
            }
         }
         if (a[n-1] == 0)
            break;
      }
      cout << m << endl;
   }

}