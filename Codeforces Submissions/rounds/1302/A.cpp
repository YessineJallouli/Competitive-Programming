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
   int n, m; cin >> n >> m;
   swap(n,m);
   int num[n][m];
   map<pair<int, int>, bool> mapa;
   for (int t = 0; t < n; t++)
      for (int k = 0; k < m; k++)
         cin >> num[t][k];
   for (int t = 0; t < m; t++)
   {
      int maxi = 2e9;
      for (int k = 0; k < n; k++)
         maxi = min(maxi, num[k][t]);
      int nb = 0;
      for (int k = 0; k < n; k++)
         if (num[k][t] == maxi)
            nb++;
      if (nb == 1)
      {
         for (int k = 0; k < n; k++)
            if (num[k][t] == maxi)
               mapa[{k,t}] = true;
      }
   }
   for (int t = 0; t < n; t++)
   {
      int mini = 0;
      for (int k = 0; k < m; k++)
         mini = max(mini, num[t][k]);
      int nb = 0;
      for (int k = 0; k < m; k++)
         if (num[t][k] == mini)
            nb++;
      if (nb == 1)
      {
         for (int k = 0; k < m; k++)
            if (num[t][k] == mini && mapa[{t,k}])
            {
                cout << t+1 << ' ' << k+1;
                return 0;
            }
      }
   }
   cout << 0 << ' ' << 0;

}