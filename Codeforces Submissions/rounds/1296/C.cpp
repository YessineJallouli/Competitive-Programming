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
      map<pair<int,int>, bool> mapa;
      map<pair<int,int>, int> d;
      int n; cin >> n;
      int x = 0, y = 0;
      mapa[{x,y}] = true;
      string Ch; cin >> Ch;
      bool b = false;
      int Am = 0, Bm = 0, mini = 1e9;
      for (int i = 0; i < n; i++)
      {
         mapa[{x,y}] = true;
         d[{x,y}] = i+1;
         char s = Ch[i];
         if (s == 'L')
            x--;
         else if (s == 'R')
            x++;
         else if (s == 'U')
            y++;
         else
            y--;
         if (mapa[{x,y}])
         {
            b = true;
            if (i+1-d[{x,y}] < mini)
            {
               mini = i+1-d[{x,y}];
               Am = d[{x,y}];
               Bm = i+1;
            }
         }
      }
      if (! b)
         cout << -1 << endl;
      else
         cout << Am << ' ' << Bm << endl;
   }
}