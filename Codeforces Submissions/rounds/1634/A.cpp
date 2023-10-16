#include <bits/stdc++.h>
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
       int n,k; cin >> n >> k;
       string s; cin >> s;
       if (k == 0) {
           cout << 1 << '\n';
           continue;
       }
       string ch = s;
       reverse(ch.begin(), ch.end());
       if (ch == s) {
           cout << 1 << '\n';
       }
       else {
           cout << 2 << '\n';
       }
   }
}