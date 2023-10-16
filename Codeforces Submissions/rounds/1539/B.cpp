/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
   SaveTime
   int n, q; cin >> n >> q;
   string s; cin >> s;
   int occ[26][n+1];
   memset(occ, 0, sizeof occ);
   for (int i = 0; i < 26; i++) {
      for (int j = 0; j < n; j++) {
         occ[i][j+1] = occ[i][j];
         if ((s[j]-'a') == i) {
            occ[i][j+1]++;
         }
      }
   }
   while (q--) {
      int a,b; cin >> a >> b; a--; b--;
      ll ans = 0;
      for (int i = 0; i < 26; i++) {
         int nb = (occ[i][b+1]-occ[i][a])*(i+1);
         ans+= nb;
      }
      cout << ans << endl;
   }
}