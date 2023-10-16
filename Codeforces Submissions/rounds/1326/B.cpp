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
#define PI 4*atan(1);

using namespace std;

int main()
{
   int n; cin >> n;
   int num[n];
   int a[n];
   for (int i= 0; i < n; i++) cin >> num[i];
   int maxi = 0;
   for (int i = 0; i < n; i++)
   {
      a[i]= num[i] + maxi;
      if (a[i] > maxi)
         maxi = a[i];
      cout << a[i] << ' ';
   }

}