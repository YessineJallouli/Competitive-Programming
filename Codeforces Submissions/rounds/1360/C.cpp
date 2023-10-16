#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
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
      int n; cin >> n;
      int num[n];
      int s = 0;
      for (int i = 0; i < n; i++) {
          cin >> num[i];
          s+= num[i];
      }
      bool b = false;
      if (s % 2 == 0)
         b = true;
      if (! b) {
         sort(num, num+n);
         for (int i = 1; i < n; i++)
            if (num[i] - num[i-1] == 1)
               b = true;
      }
      if (b)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';
   }
}