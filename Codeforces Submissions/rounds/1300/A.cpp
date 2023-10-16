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
   SaveTime
   int T; cin >> T;
   while (T--)
   {
      int nb = 0;
      int s = 0;
      int n; cin >> n; int num[n];
      for (int i=0; i < n; i++)
      {
         cin >> num[i];
         if (num[i] == 0) nb++;
         s+= num[i];
      }
      s+= nb;
      if (s == 0)
         nb++;
      cout << nb << endl;
   }

}