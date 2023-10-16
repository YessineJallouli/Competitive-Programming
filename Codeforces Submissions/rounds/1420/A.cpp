#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      bool tri = true;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      for (int i = 1; i < n; i++) {
         if (num[i] >= num[i-1])
            tri = false;
      }
      if (tri)
         cout << "NO" << endl;
      else
         cout << "YES" << endl;
   }
}