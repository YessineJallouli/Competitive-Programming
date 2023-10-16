#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      map<int,int> nb;
      int mx = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         nb[num[i]]++;
         if (nb[num[i]] > mx)
            mx = nb[num[i]];
      }
      if (n%2)
         cout << max(2*mx-n,1) << endl;
      else
         cout << max(2*mx-n,0) << endl;
      nb.clear();
   }
}