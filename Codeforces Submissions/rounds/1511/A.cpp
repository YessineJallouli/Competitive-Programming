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
      int n; cin >> n;
      int nb = 0;
      while (n--) {
         int x; cin >> x;
         if (x != 2)
            nb++;
      }
      cout << nb << endl;
   }
}