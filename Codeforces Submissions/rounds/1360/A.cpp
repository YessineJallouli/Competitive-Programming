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
      int a, b; cin >> a >> b;
      if (a > b) swap(a,b);
      int a1 = 2*a;
      cout << max(a1,b) * max(a1,b) << '\n';
   }
}