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
      int n; cin >> n;
      string s,t; cin >> s >> t;
      vector<pair<char, char>> v;
      for (int i = 0; i < n; i++) {
         if (s[i] != t[i])
            v.pb({s[i], t[i]});
      }
      if (v.size() != 2 && v.size() != 0)
         cout << "NO" << endl;
      else if (v.size() == 0)
         cout << "YES" << endl;
      else
      {
         if (v[0].first == v[1].first && v[0].second == v[1].second)
            cout << "YES" << endl;
         else
            cout << "NO" << endl;
      }
   }
}