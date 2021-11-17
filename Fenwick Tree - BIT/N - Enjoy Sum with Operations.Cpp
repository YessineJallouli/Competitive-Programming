//https://www.spoj.com/problems/SUMSUM/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 1e5+7;
int num[N];
const int mx = 3e8;
int n;

int tree[N][30];

void upd(int x, int bit, int val) {
   for (; x <= n; x+=x&(-x))
      tree[x][bit]+= val;
}

int get(int x, int bit) {
   int res = 0;
   for (; x; x-=x&(-x))
      res+= tree[x][bit];
   return res;
}

ll f(int a) {
   return 1LL*a*(a-1)/2;
}


int main() {
   SaveTime
   cin >> n;
   int Q; cin >> Q;
   memset(tree, 0, sizeof tree);
   for (int i = 1; i <= n; i++) {
      cin >> num[i];
      for (int j = 0; (1 << j) < mx; j++) {
         int bit = (num[i] & (1 << j)) > 0;
         upd(i, j, bit);
      }
   }
   while (Q--) {
      int t; cin >> t;
      if (t == 2) {
         string s; cin >> s;
         int a,b; cin >> a >> b;
         if (a > b) swap(a,b);
         if (a== b) {
            cout << 0 << '\n';
            continue;
         }
         ll ans = 0;
         for (int i = 0; i < 30; i++) {
            int nb1 = get(b,i) - get(a-1,i);
            int nb0 = b-a+1 - nb1;
            if (s == "OR")
               ans += (f(nb1)+(1LL*nb0*nb1))*(1LL<<i);
            else if (s == "XOR") {
               ans += (1LL*nb0*nb1)*(1LL<<i);
            }
            else {
               ans += f(nb1)*(1LL<<i);
            }
         }
         cout << ans << '\n';
      }
      else {
         int a,b; cin >> a >> b;
         for (int i = 0; (1 << i) < mx; i++) {
            int bit1 = (a & (1 << i)) > 0;
            int bit2 = (num[b] & (1 << i)) > 0;
            upd(b, i, bit1-bit2);
         }
         num[b] = a;
      }
   }
}
