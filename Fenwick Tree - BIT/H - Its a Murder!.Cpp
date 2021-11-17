//https://www.spoj.com/problems/DCEPC206/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;
const int N = 1e6 + 7;
ll tree[N];
int n;

// Fenwick tree is used only for sum and xor (I guess)

void upd(int x, int val) {
   for (; x < N; x += x&(-x))
      tree[x]+= val;
}

ll get(int x) {
   ll res = 0;
   for (; x; x-= x&(-x))
      res+= tree[x];
   return res;
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      cin >> n;
      ll ans = 0;
      int a[n];
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         a[i] = x;
         if (x == 0)
            continue;
         ans+= get(x-1);
         upd(x,x);
      }
      for (int i = 0; i < n; i++) {
         if (a[i])
            upd(a[i], -a[i]);
      }
      cout << ans << '\n';
   }
}
