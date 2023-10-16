#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int n; cin >> n;
   vector<int> ans(n+1, 0);
   int id = 1;
   for (int i = 2; i <= n; i++) {
      cout << "? " << i << ' ' << id << endl;
      int k; cin >> k;
      cout << "? " << id << ' ' << i << endl;
      int k1; cin >> k1;
      if (k > k1) {
         ans[i] = k;
      }
      else {
         ans[id] = k1;
         id = i;
      }
   }
   cout << "! ";
   for (int i = 1; i <= n; i++) {
      if (ans[i] == 0)
         cout << n << ' ';
      else
         cout << ans[i] << ' ';
   }
}