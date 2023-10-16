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
      for (int i = 0; i < n; i++)
         cin >> num[i];
      sort(num, num+n);
      bool b = true;
      for (int i = 0; i < n-1; i++) {
         if (num[i+1]-num[i] > 1)
            b= false;
      }
      if (b)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';

   }
}