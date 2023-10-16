#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);

using namespace std;

const int N = 1e6+7; // n max
int n;
int c[N];
const int LOG = 20;
ll Sp[N][LOG];

void build() {
   for (int i = 0; i < n; i++)
      Sp[i][0] = c[i];
   for (int j = 1; j < LOG; j++) {
      for (int i = 0; i+ (1<<j)-1 < n; i++) {
         Sp[i][j] = min(Sp[i][j-1], Sp[i+(1<<(j-1))][j-1]);
      }
   }
}

int get(int qs, int qe) {
   int len = qe-qs+1;
   int k = 0;
   while (1 << (k+1) <= len)
      k++;
   return min(Sp[qs][k], Sp[qe-(1<<k)+1][k]);
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int D; cin >> n >> D;
      int len = n/__gcd(n,D);
      int a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      bool visite[n];
      memset(visite, false,sizeof visite);
      vector<int> b;
      for (int i = 0; i < n; i++) {
         if (visite[i])
            continue;
         int j = i;
         while (true) {
            visite[j] = true;
            b.push_back(a[j]);
            j = (j-D+n)%n;
            if (visite[j])
               break;
         }
      }
      bool ans = true;
      for (int i = 0; i < n; i+= len) {
         bool zero = false;
         for (int j = i; j < i+len; j++) {
            if (b[j] == 0)
               zero = true;
         }
         if (! zero)
            ans = false;
      }
      if (! ans) {
         cout << -1 << '\n';
         continue;
      }
      for (int i = 0; i < n; i++)
         c[i] = b[i];
      build();
      int d = 0, f = len;
      int res = -1;
      while (d <= f) {
         int m = (d+f)/2;
         bool can = true;
         for (int i = 0; i < n; i+= len) {
            for (int j = i; j < i+len; j++) {
               int bit;
               if (j+m < i+len) {
                  bit = get(j, j+m);
               }
               else {
                  bit = get(j, i+len-1);
                  int part2 = m-(i+len-j);
                  bit = bit&(get(i, i+part2));
               }
               if (bit == 1)
                  can = false;
            }
         }
         if (can) {
            res = m;
            f = m-1;
         }
         else {
            d = m+1;
         }
      }
      cout << res << '\n';
   }
}