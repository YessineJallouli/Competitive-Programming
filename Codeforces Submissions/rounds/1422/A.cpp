#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int a, b, c; cin >> a >> b >> c;
      int d = max({a,b,c})+1;
      cout << d << endl;
   }
}