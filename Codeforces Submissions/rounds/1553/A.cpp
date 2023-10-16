
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
      if (n%10 == 9) {
         cout << (n+9)/10 << endl;
      }
      else
         cout << n/10 << endl;
   }
}