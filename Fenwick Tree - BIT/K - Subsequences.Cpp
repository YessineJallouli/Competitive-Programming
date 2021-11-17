//https://codeforces.com/problemset/problem/597/C
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
const int K = 12;
ll tree[N][K],a[N];

int n,k;

ll get(int x, int pos) {
   ll res = 0;
   for (; x; x-=x&(-x))
      res+= tree[x][pos];
   return res;
}

void upd(int x, int pos, ll val) {
   for (; x < N; x+= x&(-x))
      tree[x][pos]+= val;
}

int main() {
   SaveTime
   cin >> n >> k;
   k++;
   int mx = 0;
   for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mx = max(1LL*mx, a[i]);
   }
   memset(tree, 0, sizeof tree);
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= k; j++) {
         if (j == 1)
            upd(a[i],j,1);
         else {
            ll x = get(a[i]-1, j-1);
            upd(a[i],j,x);
         }
      }
   }
   cout << get(mx, k);
}
