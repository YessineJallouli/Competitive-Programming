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
      int num[2*n];
      vector<int> v;
      for (int i = 0; i < 2*n; i++)
         cin >> num[i];
      map<int, bool> m;
      for (int i = 0; i < 2*n; i++) {
         int nn = num[i];
         if (m[nn] == false) {
            m[nn] = true;
            v.pb(nn);
         }
      }
      for (int i : v)
         cout << i << ' ';
      cout << endl;
      v.clear();
      m.clear();
   }
}