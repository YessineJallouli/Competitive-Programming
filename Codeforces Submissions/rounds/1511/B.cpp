#include <bits/stdc++.h>
#define ll long long
using namespace std;

int len(int n) {
   if (n == 0)
      return 0;
   return 1+len(n/10);
}

int main()
{
   int T; cin >> T;
   while (T--) {
      int a,b,c; cin >> a >> b >> c;
      int x = 1;
      while (c != len(x)) {
         x*= 3;
      }
      int y = x,z = x;
      while (len(y) != a) {
         y*= 2;
      }
      while (len(z) != b)
         z*= 5;
      cout << y << ' ' << z << endl;
   }
}