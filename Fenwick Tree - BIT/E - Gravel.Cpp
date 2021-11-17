//https://www.codechef.com/problems/SPREAD
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

const int N = 1e6 + 7;
ll tree[N];

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

int n;

int main() {
   SaveTime
   int q,c; cin >> n >> q >> c;
   upd(1,c);
   upd(n+1, -c);
   while (q--) {
      char s; cin >> s;
      if (s == 'Q') {
         int id; cin >> id;
         cout << get(id) << '\n';
      }
      else {
         int x,y,z; cin >> x >> y >> z;
         upd(x,z);
         upd(y+1, -z);
      }
   }
}
