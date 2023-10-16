#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SAVETIME ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
   SAVETIME
   int T; cin >> T;
   while (T--) {
      int a,b,d; cin >> a >> b >> d;
      if (a > b)
         swap(a,b);
      int q = b/a;
      if (b%a != 0)
         q++;
      if (q-1 <= d) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}