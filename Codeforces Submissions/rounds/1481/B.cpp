#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      if (k > 100000) {
         cout << -1 << endl;
         continue;
      }
      bool b = true;
      for (int i = 0; i < k; i++) {
         for (int j = 0; j < n-1; j++) {
            if (num[j] < num[j+1]) {
               num[j]++;
               if (i == k-1) {
                  b = false;
                  cout << j+1 << endl;
               }
               break;
            }
         }
      }
      if (b)
         cout << -1 << endl;
   }
}