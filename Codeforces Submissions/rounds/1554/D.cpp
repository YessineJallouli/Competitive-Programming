/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int m = n/2;
      for (int i = 0; i < m; i++)
         cout << 'a';
      cout << 'b';
      for (int i = 0; i < m-1; i++)
         cout << 'a';
      if (n%2 && n != 1)
         cout << 'c';
      cout << '\n';
   }
}