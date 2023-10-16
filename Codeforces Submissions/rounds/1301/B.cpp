/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define pb push_back
 
using namespace std;
 
 
int main()
{
   int T; cin >> T;
   while (T--)
   {
      int n; cin >> n; int num[n];
      bool allZ = true;
      for (int t = 0; t < n; t++)
      {
         cin >> num[t];
         if (num[t] != -1)
            allZ = false;
      }
      if (allZ)
         cout << 0 << ' ' << 0 << endl;
      else
      {
         int miniM = 1e9; int maxiM = 0;
         for (int t=0; t < n; t++)
         {
            if (num[t] != -1)
               if ((num[t+1] == -1 && t+1 < n) || (num[t-1] == -1 && t-1 >=0))
               {
                  miniM = min(miniM, num[t]);
                  maxiM = max(maxiM, num[t]);
               }
         }
         int h = (miniM + maxiM)/2;
         for (int t = 0; t < n; t++)
            if (num[t] == -1 ) num[t] = h;
         int maxi = 0;
         for (int t = 1; t < n; t++)
            maxi = max(maxi, abs(num[t]-num[t-1]));
         cout << maxi << ' ' << h << endl;
      }
   }
}