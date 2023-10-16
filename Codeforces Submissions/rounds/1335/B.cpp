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
      double n, a, b;
      cin >> n >> a >> b;
      string s = "";
      char c = 'a';
      for (int i = 0; i < b; i++) {
         s+= c;
         c++;
      }
      string h = "";
      while (h.size() <= n)
         h+= s;
      for (int i = 0; i < n; i++)
         cout << h[i];
      cout << endl;

   }
}