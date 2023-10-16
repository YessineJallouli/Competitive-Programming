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
   int T; cin >> T;
   while (T--)
   {
      int n; cin >> n;
      int num[2*n];
      for (int i=0; i < 2*n; i++)
         cin >> num[i];
      sort(num, num+2*n);
      cout << num[n]-num[n-1] << endl;
   }

}