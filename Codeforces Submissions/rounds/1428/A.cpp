#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
   int T; cin>> T;
   while (T--) {
   int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
   if (x1 == x2 && y1  == y2)
      cout << 0 << endl;
   else if (x1 == x2 || y1 == y2) {
      cout << abs(y2-y1)+abs(x2-x1) << endl;
   }
   else
      cout << abs(y2-y1)+abs(x2-x1)+2 << endl;
   }
}