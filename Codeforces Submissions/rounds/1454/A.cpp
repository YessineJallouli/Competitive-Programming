#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n%2 == 0) {
         for (int i = n; i >= 1; i--) {
            cout << i << ' ';
         }
      }
      else {
         cout << n << ' ';
         for (int i = 1; i < n; i++) {
            cout << i << ' ';
         }
      }
      cout << endl;
   }
}