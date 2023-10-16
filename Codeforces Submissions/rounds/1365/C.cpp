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
   int n; cin >> n;
   int a[2*n], b[n];
   int pos[n+1];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
   }
   map<int,int> m;
   int ans = 0;
   for (int i = 0; i < n; i++) {
      cin >> b[i];
      int p = pos[b[i]];
      int d = p-i;
      if (d < 0)
         d+= n;
      m[d]++;
      ans = max(ans, m[d]);
   }
   cout << ans;

}