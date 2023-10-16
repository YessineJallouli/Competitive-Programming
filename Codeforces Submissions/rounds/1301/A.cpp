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
      string a,b,c; cin >> a >> b >> c;
      int n = a.length();
      bool bb = true;
      for (int k = 0; k < n; k++)
      {
         if (a[k] != b[k] && a[k] != c[k] && b[k] != c[k])
            bb = false;
         if (a[k] == b[k] && b[k] != c[k])
            bb = false;
      }
      if (bb) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}