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
   int n; cin >> n;
   int num[n+1];
   for (int i = 1; i <= n; i++)
      cin >> num[i];
   bool visited[n+1] = {false};
   map<int, ll> mapa;
   unsigned long long s = 0, sM = 0;
   int i = 1;
   ll maxi = 0;
   for (int i = 1; i<= n; i++)
   {
      mapa[num[i]-i] += num[i];
      maxi = max(mapa[num[i]-i], maxi);
   }
   cout << maxi;
}