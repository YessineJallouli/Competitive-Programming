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
      int n, x,y; cin >> n >> x >> y;
      int maxi = 0, mini = 0;
      if (x + y > n) maxi = n;
      else if (x+ y == n) maxi = n-1;
      else maxi = x+y-1;
      if (x + y <= n) mini = 1;
      else mini = (x+y)-n+1;
      if (x == n && y == n)
         mini = maxi = n;
      cout << mini << ' ' << maxi << endl;
   }
}