/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
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
      int x, n, m;
      cin >> x >> n >> m;
      while (x > 20 && n > 0) {
         x = x/2 + 10;
         n--;
      }
      double h = x;
      int f = ceil(h/10.0);
      if (m >= f)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}