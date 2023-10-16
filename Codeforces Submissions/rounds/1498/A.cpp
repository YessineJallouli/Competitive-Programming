#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SAVETIME ios_base::sync_with_stdio(false); cin.tie(NULL);

long long sumD(long long n) {
   if (n == 0)
      return 0;
   return n%10 + sumD(n/10);
}

bool tr(long long n) {
   if (__gcd(n, sumD(n)) != 1)
      return true;
   return false;
}

int main() {
   SAVETIME
   int T; cin >> T;
   while (T--) {
      long long n; cin >> n;
      if (tr(n)) {
         cout << n << endl;
      }
      else if (tr(n+1)) {
         cout << n+1 << endl;
      }
      else
         cout << n+2 << endl;
   }
}