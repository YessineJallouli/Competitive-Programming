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
      string s; cin >> s;
      int d = 1;
      int dM = 1;
      for (int i = 0; i < s.size(); i++) {
         if (s[i] == 'L') {
            d++; continue;
         }
         dM = max(d, dM);
         d = 1;
      }
      cout << max(d, dM) << endl;
   }
}