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
   int t; cin >> t;
   for (int k = 0; k < t; k++)
   {
      vector<pair<int,int>> v;
      int n; cin >> n;
      int num[n];
      for (int h = 0; h < n; h++)
         cin >> num[h];
      bool no = true;
      for (int l = 0; l < n-1; l++)
         if (abs(num[l]- num[l+1]) > 1)
         {
            no = false;
            cout << "YES" << endl;
            cout << l+1 << ' ' << l+2 << endl;
            break;
         }
      if (no)
         cout << "NO" << endl;
   }



}