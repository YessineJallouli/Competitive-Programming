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
   for (int i= 0; i < T; i++)
   {
      int n; cin >> n;
      int num[n];
      for (int k = 0; k < n; k++) cin >> num[k];
      int incr = n-1;
      for (int k = 0; k < n; k++)
         if (num[k] < k)
         {
            incr = k-1;
            break;
         }
      int decr = 0;
      for (int k = n-1; k >= 0; k--)
      {
         if (num[k] < n-k-1)
         {
             decr = k+1;
             break;
         }
      }
      if (incr >= decr)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;

   }
}