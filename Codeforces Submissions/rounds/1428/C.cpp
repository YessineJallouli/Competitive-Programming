#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n = s.length();
      int sum = 0;
      int ans = 0;
      for (int i = n-1; i >= 0; i--) {
         if (s[i] == 'A' && sum == 0) {
            ans++;
         }
         else if (s[i] == 'A')
            sum--;
         else
            sum++;
      }
      cout << ans+sum%2 << endl;
   }
}