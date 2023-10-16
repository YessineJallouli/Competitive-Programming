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
   int T; cin >> T;
   while (T--)
   {
      int n; cin >> n;
      string s = "";
      if (n == 1)
         cout << -1 << endl;
      else if (n % 3 == 0 || n% 3 == 2)
      {
         for (int i = 0; i < n-1; i++)
            s += '5';
         s+= '3';
         cout << s << endl;
      }
      else if (n % 3 == 1)
      {
         for (int i = 0; i < n-2; i++)
            s+= '5';
         s+= "33";
         cout << s << endl;
      }
   }
}