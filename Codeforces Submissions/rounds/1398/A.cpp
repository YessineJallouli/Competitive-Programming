#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      if (num[0]+num[1] <= num[n-1])
          cout << 1 << ' ' << 2 << ' ' << n << endl;
      else
          cout << -1 << endl;
   }
}