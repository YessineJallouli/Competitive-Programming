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
      int num[n];
      bool odd = false;
      bool even = false;
      int s = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> num[i];
         if (num[i] % 2 == 0)
            odd = true;
         else
            even = true;
         s+= num[i];
      }
      if (s % 2 == 1)
         cout << "YES" << endl;
      else if (even && odd)
         cout << "YES" << endl;
      else
         cout << "NO" << endl;

   }
}