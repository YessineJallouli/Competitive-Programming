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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int sum = 0;
      while (n) {
         sum = max(sum, n%10);
         n/=10;
      }
      cout << sum << endl;
   }
}