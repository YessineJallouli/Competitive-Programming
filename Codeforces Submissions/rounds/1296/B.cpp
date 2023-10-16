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
      int s; cin >> s;
      int k = 0;

      while (s > 9)
      {
         int o = s%10;
         k += s-o;
         s = s/10 + o;
      }
      cout << k+s << endl;
   }
}