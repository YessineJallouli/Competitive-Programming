#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int d; cin>> d;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      sort(num, num+n);
      if (num[n-1] <= d) {
         cout << "yes" << endl;
      }
      else if (num[0]+num[1] <= d)
         cout << "yes" << endl;
      else
         cout << "no" << endl;
   }
}