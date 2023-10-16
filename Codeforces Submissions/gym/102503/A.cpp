/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define pb push_back

int a,b,c,d,h;
bool sum(int a, int b, int c)
{
   return (a+b+c >= h);
}

using namespace std;

int main()
{
   cin >> a >> b >> c >> d >> h;
   if (sum(a,b,c) || sum(a,b,d) || sum(a,c,d) || sum(b,c,d))
      cout << "WAW";
   else
      cout << "AWW";
}