/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define pb push_back

using namespace std;

int main()
{
   int n; cin >> n;
   if (n%3 != 2)
      cout << 1 << ' ' << 1 <<  ' ' << n-2;
   else
      cout << 1 << ' ' << 2  << ' ' << n-3;
}