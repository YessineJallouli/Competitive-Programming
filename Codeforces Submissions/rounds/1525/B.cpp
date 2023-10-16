#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      bool b = true;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         if (num[i] != i+1)
            b =false;
      }
      if (b) {
         cout << 0 << endl;
         continue;
      }
      if (num[n-1] == 1 && num[0] == n) {
         cout << 3 << endl;
         continue;
      }
      if (num[n-1] == n || num[0] == 1) {
         cout << 1 << endl;
         continue;
      }
      else {
         cout << 2 << endl;
      }
   }
}