#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int a, b,c,d; cin >> a >> b >> c >> d;
      int x,y,x1,y1, x2, y2; cin >> x >> y >> x1 >> y1 >> x2 >> y2;
      int dx = b-a;
      int dy = d-c;
      x+= dx; y+= dy;
      if (x1 == x2 && y1 == y2)
         cout << "NO" << endl;
      else if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
         if (x2 - x1 == 0 && a+b > 0)
            cout << "NO" << endl;
         else if (y2-y1 == 0 && c+d > 0)
            cout << "NO" << endl;
         else
            cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}