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
      ll ans = 0;
      for (int i = 0; i < n-1; i++) {
         if (num[i] > num[i+1])
            ans+= num[i]-num[i+1];
      }
      cout << ans << endl;
   }
}