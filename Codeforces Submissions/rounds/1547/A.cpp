/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int x1,y1,x2,y2,x3,y3; cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
      int ans = abs(x1-x2) + abs(y1-y2);
      if (x1 == x2 && x2 == x3) {
         if (y1 > y2)
            swap(y1, y2);
         if (y3 > y1 && y3 < y2)
            cout << ans+2 << endl;
         else
            cout << ans << endl;
      }
      else if (y1 == y2 && y2 == y3) {
         if (x1 > x2)
            swap(x1, x2);
         if (x3 > x1 && x3 < x2)
            cout << ans+2 << endl;
         else
            cout << ans << endl;
      }
      else
         cout << ans << endl;
   }
}