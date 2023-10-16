#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll n, k; cin >> n >> k;
      int num[n];
      int r1[n];
      int maxi = INT_MIN;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         maxi = max(num[i], maxi);
      }
      int mm = INT_MIN;
      for (int i = 0; i < n; i++) {
         num[i] = maxi-num[i];
         mm = max(num[i], mm);
      }
      for (int i = 0; i < n; i++) {
         r1[i] = mm-num[i];
      }
      if (k%2 == 1) {
         for (int i : num)
            cout << i << ' ';
      }
      else
         for (int i : r1)
             cout << i << ' ';
      cout << endl;

   }
}