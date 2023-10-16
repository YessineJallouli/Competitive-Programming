#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      ll s = 0;
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         s+= x;
         num[i] = x;
      }
      if (s == 0) {
         cout << "NO" << endl;
         continue;
      }
      sort(num, num+n);
      cout << "YES" << endl;
      if (s > 0) {
      for (int i = 0; i < n; i++) {
         if (num[i] > 0)
            cout << num[i]<< ' ';
      }
      for (int i = 0; i < n; i++) {
         if (num[i] <= 0)
            cout << num[i] << ' ';
      }
      }
      if (s < 0)
      {
         for (int i = 0; i < n; i++) {
         if (num[i] < 0)
            cout << num[i] << ' ';
         }
         for (int i = 0; i < n; i++) {
            if (num[i] >= 0)
               cout << num[i]<< ' ';
          }
      }
      cout << endl;
   }
}