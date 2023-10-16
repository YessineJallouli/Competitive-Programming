#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   freopen("equal.in", "r", stdin);
   int T; cin >> T;
   while (T--) {
      int a,b,c; cin >> a >> b >> c;
      if (a == b || b == c || a == c)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}