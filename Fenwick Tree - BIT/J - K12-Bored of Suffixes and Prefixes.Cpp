//https://www.spoj.com/problems/KOPC12G/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int N = 507;
ll tree[N][N];
char grid[N][N];
int n;

void upd(int x, int y, int val) {
   for (; x <= n; x += x&(-x))
      for (int j = y; j <= n; j+= j&(-j))
         tree[x][j]+= val;
}

ll get(int x, int y) {
   ll res = 0;
   for (; x; x-= x&(-x))
      for (int j = y; j; j-=j&(-j))
         res+= tree[x][j];
   return res;
}

int main() {
   int T; scanf("%d", &T);
   while (T--) {
      int q; scanf("%d%d", &n, &q);
      memset(tree, 0, sizeof tree);
      for (int i = 0; i < n; i++) {
         char s[n]; scanf("%s", s);
         for (int j = 0; j < n; j++) {
            upd(i+1, j+1, s[j]-'A'+1);
            grid[i][j] = s[j];
         }
      }
      while (q--) {
         int t; cin >> t;
         if (t == 1) {
            int a,b,c,d; scanf("%d%d%d%d", &a, &b,&c,&d);
            a++; b++; c++; d++;
            printf("%lld\n", get(c,d) - get(a-1, d) - get(c, b-1) + get(a-1, b-1));
         }
         else {
            int x; scanf("%d", &x);
            if (x == 0) {
               int y; scanf("%d", &y);
               char s[n]; scanf("%s", s);
               for (int i = 0; i < n; i++) {
                  upd(y+1, i+1, s[i]-grid[y][i]);
                  grid[y][i] = s[i];
               }
            }
            else {
               int y; scanf("%d", &y);
               char s[n]; scanf("%s", s);
               for (int i = 0; i < n; i++) {
                  upd(i+1, y+1, s[i]-grid[i][y]);
                  grid[i][y] = s[i];
               }
            }
         }
      }
   }
}
