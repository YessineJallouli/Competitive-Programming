#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string a,b; cin >> a >> b;
      int diff = 0;
      bool ans = true;
      for (int i = 0; i < n; i++) {
         if (a[i] == '0')
            diff++;
         else
            diff--;
         if (i == n-1 && a[i] != b[i] && diff != 0) {
            ans = false;
         }
         else if (a[i] == b[i] && a[i+1] != b[i+1] && diff != 0)
            ans = false;
         else if (a[i+1] == b[i+1] && a[i] != b[i] && diff != 0)
            ans = false;
      }
      if (ans)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}