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
   int n, m; cin >> n >> m;
   string s[n], t1[m];
   for (int t = 0; t < n; t++)
      cin >> s[t];
   for (int t = 0; t < m; t++)
      cin >> t1[t];
   int q; cin >> q;
   for (int h = 0; h < q; h++)
   {
      int y; cin >> y;
      int l = y % n, l1 = y % m;
      if (l-1 < 0) l += n; if (l1-1 < 0) l1 += m;
      cout << s[l-1] << t1[l1-1] << endl;
   }
}