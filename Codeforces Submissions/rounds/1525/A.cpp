#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int k; cin >> k;
      cout << 100/__gcd(k,100) << endl;
   }
}