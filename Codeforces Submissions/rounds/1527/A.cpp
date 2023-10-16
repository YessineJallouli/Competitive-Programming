#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int ans = 1;
      while (ans*2 <= n) {
         ans*= 2;
      }
      cout << ans-1 << endl;
   }
}