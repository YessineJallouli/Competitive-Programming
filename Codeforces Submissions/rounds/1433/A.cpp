#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int c = ((n%10)-1)*10;
      int l = 0;
      while (n != 0) {
         l++;
         n/=10;
      }
      for (int i = 1; i <= l; i++) {
         c+=i;
      }
      cout << c << endl;
   }
}