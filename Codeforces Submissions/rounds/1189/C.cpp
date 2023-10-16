#include <bits/stdc++.h>
#define ll long long
using namespace std;

string inp;
char a1,a2;
int p,sz,sol;

int main()
{
   int n; cin >> n;
   int N = n;
   int a[n];
   int nb = 0;
   while (N/= 2) {
      nb++;
   }
   vector<vector<pair<int,int>>> v(nb+1);
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v[0].push_back({x,0});
   }
   int pw = 1;
   for (int i = 1; i <= nb; i++) {
      for (int j = 0; j < v[i-1].size()-pw; j++) {
         int h = v[i-1][j].first%10 + v[i-1][j+pw].first%10;
         int tnt = v[i-1][j].second+ v[i-1][j+pw].second;
         if (h > 9) {
            tnt++;
         }
         v[i].push_back({h, tnt});
      }
      pw*= 2;
   }
   int q; cin >> q;
   for (int i = 0; i < q; i++) {
      int x, y; cin >> x >> y;
      x--; y--;
      int K = y-x+1;
      int nn = 0;
      while (K/=2)
         nn++;
      cout << v[nn][x].second << endl;
   }

}