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

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--)
   {
      int x, y, a, b; cin >> x >> y >> a >> b;
      if ((y-x) % (a+b) == 0)
         cout << (y-x)/ (a+b) << endl;
      else
         cout << -1 << endl;
   }
}