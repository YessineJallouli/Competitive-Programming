#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      map<int,int> nb;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         nb[num[i]]++;
      }
      for (int i = 2*n; i >= 1; i--) {
         if (nb[i] >= 1 && nb[i+1] == 0) {
            nb[i]--;
            nb[i+1]++;
         }
      }
      int ans = 0;
      for (int i = 2*n+1; i >= 1; i--) {
         if (nb[i] != 0)
            ans++;
      }
      cout << ans << endl;
      nb.clear();
   }
}