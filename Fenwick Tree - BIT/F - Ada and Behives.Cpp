//https://www.spoj.com/problems/ADABEHIVE/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int N = 2e3 + 7;
ll tree[N][N], grid[N][N];
int n,m;

// Fenwick tree is used only for sum and xor (I guess)

void upd(int x, int y, int val) {
   for (; x <= n; x += x&(-x))
      for (int j = y; j <= m; j+= j&(-j))
         tree[x][j]+= val;
}

ll get(int x, int y) {
   ll res = 0;
   for (; x; x-= x&(-x))
      for (int j = y; j ; j-=j&(-j))
         res+= tree[x][j];
   return res;
}

int main() {
   SaveTime
   int q;
   cin >> n >> m >> q;
   for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
         tree[i][j] = grid[i][j] = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> grid[i][j];
         upd(i,j,grid[i][j]);
      }
   }
   while (q--) {
      int t; cin >> t;
      if (t == 1) {
         int x,y,c; cin >> x >> y >> c;
         upd(x,y,c);
      }
      else {
         int a,b,c,d; cin >> a >> b >> c >> d;
         cout << get(c,d) - get(a-1, d) - get(c, b-1) + get(a-1, b-1) << '\n';
      }
   }
}
