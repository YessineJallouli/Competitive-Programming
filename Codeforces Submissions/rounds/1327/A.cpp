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
      ull n, k; cin >> n >> k;
      bool b = true;
      if ((n-k) % 2 == 1) b = false;
      ull h = (((1 + (k-1)*2) + 1) * k) / 2;
      if (h > n) b = false;
      if (b)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;
   }
}