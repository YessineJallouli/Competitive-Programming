#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int x, y; cin >> x >> y;
      string s; cin >> s;
      int n = s.size();
      int R,U,L,D; R = L = D = U = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'R')
            R++;
         if (s[i] == 'L')
            L++;
         if (s[i] == 'U')
            U++;
         if (s[i] == 'D')
            D++;
      }
      bool b = true;
      //cout << L << endl;
      if (x > 0 && R < x)
         b = false;
      if (x < 0 && L < abs(x))
         b = false;
      if (y > 0 && U < y)
         b = false;
      if (y < 0 && D < abs(y))
         b = false;
      if (b)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}