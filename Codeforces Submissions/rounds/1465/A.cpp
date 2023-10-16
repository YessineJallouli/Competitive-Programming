#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      int nb = 0;
      for (int i = n-1; i >= 0; i--) {
         if (s[i] != ')')
            break;
         nb++;
      }
      if (nb > n-nb) {
         cout << "YES" << endl;
      }
      else
         cout << "NO" << endl;
   }
}