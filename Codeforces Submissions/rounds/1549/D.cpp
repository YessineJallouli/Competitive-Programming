#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;


const int N = 3e5+7;
const int LOG = 20;
ll Sp[N][LOG];
ll a[N];
int n;

void build() {
   for (int i = 0; i < n; i++)
      Sp[i][0] = a[i];
   for (int j = 1; j < LOG; j++) {
      for (int i = 0; i+ (1<<j)-1 < n; i++) {
         Sp[i][j] = __gcd(Sp[i][j-1], Sp[i+(1<<(j-1))][j-1]);
      }
   }
}

ll get(int qs, int qe) {
   int len = qe-qs+1;
   int k = 0;
   while (1 << (k+1) <= len)
      k++;
   return __gcd(Sp[qs][k], Sp[qe-(1<<k)+1][k]);
}

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      cin >> n;
      ll b[n];
      for (int i = 0; i < n; i++) {
         cin >> b[i];
      }
      if (n == 1) {
         cout << 1 << '\n';
         continue;
      }
      for (int i = 0; i < n-1; i++)
         a[i] = abs(b[i]-b[i+1]);
      n--;
      build();
      int res = 0;
      for (int i = 0; i < n; i++) {
         int d = i, f = n-1;
         int ans = 0;
         while (d <= f) {
            int m = (d+f)/2;
            if (get(i,m) == 1) {
               f = m-1;
            }
            else {
               d = m+1;
               ans = m-i+1;
               res = max(ans, res);
            }
         }
      }
      cout << res+1 << '\n';
   }
}