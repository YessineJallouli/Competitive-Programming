/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 2e3+7;

int delta[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}};
int grid[mx][mx];

int n,m;

ll best_portal(int w, int d, int f, bool b) {
   bool visite[n][m];
   memset(visite, false, sizeof visite);
   vector<pair<int,int>> v;
   v.push_back({d,f});
   ll mov = 0;
   ll bestcost = LLONG_MAX;
   visite[d][f] = true;
   if (grid[d][f] != 0) {
      bestcost = min(bestcost, 1LL*grid[d][f]);
   }
   ll WholePath = LLONG_MAX;
   while (! v.empty()) {
      mov+= w;
      vector<pair<int,int>> v1;
      for (auto i : v) {
         int y = i.first;
         int x = i.second;
         for (int t = 0; t < 4; t++) {
            int yDep = y+delta[t][0];
            int xDep = x+delta[t][1];
            if (xDep >= 0 && yDep >= 0 && xDep < m && yDep < n && grid[yDep][xDep] != -1) {
               if (visite[yDep][xDep])
                  continue;
               v1.push_back({yDep, xDep});
               visite[yDep][xDep] = true;
               if (grid[yDep][xDep] != 0) {
                  ll cost  = mov + grid[yDep][xDep];
                  if (cost < bestcost) {
                     bestcost = cost;
                  }
               }
               if (yDep == n-1 && xDep == m-1) {
                  WholePath = mov;
               }
            }
         }
      }
      v.swap(v1);
   }
   if (b) {
      return bestcost;
   }
   else {
      return WholePath;
   }
}

int main() {
   SaveTime
   int w; cin >> n >> m >> w;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         cin >> grid[i][j];

   ll BestFromStart = best_portal(w,0,0, true);
   ll BestFromEnd = best_portal(w,n-1,m-1, true);
   ll BestWithoutPortal = best_portal(w,0,0, false);
   if (BestFromEnd == LLONG_MAX || BestFromStart == LLONG_MAX) {
      if (BestWithoutPortal == LLONG_MAX) {
         cout << -1;
      }
      else {
         cout << BestWithoutPortal;
      }
   }
   else {
      ll sum1 = BestFromEnd + BestFromStart;
      if (BestWithoutPortal == LLONG_MAX) {
         cout << sum1;
      }
      else {
         cout << min(sum1, BestWithoutPortal);
      }
   }
}