#include <bits/stdc++.h>
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      vector<long long> v1;
      vector<long long> v2;
      for (int i = 0; i < 2*n; i++) {
         long long x, y; cin >> x >> y;
         if (x == 0) v1.push_back(abs(y));
         if (y == 0) v2.push_back(abs(x));
      }
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());
      long double ans = 0;
      for (int i = 0; i < n; i++) {
         ans+= sqrt(v1[i]*v1[i] + v2[i]*v2[i]);
      }
      cout.precision(25);
      cout << ans << endl;
   }
}