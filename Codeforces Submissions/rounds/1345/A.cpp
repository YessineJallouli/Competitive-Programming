#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      int a, b;
      cin >> a >> b;
      if (a == 2 && b == 2)
         cout << "YES\n";
      else if (min(a,b) >= 2)
         cout << "NO\n";
      else
         cout << "YES\n";
   }
}