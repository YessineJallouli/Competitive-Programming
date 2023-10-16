#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      long long n, m; cin >> m >> n;
      long long x; cin >> x;
      long long h = x/m;
      if (x%m != 0)
         h++;
      long long d = m-(h*m-x)-1;
      cout << d*n+h << endl;
   }
}