#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int n, w; cin >> n >> w;
   int a[n], b[w];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   for (int i = 0; i < w; i++)
      cin >> b[i];
   if (w == 1) {
      cout << n;
      return 0;
   }
   int s[w-1];
   int ch[n-1];
   for (int i = 0; i < w-1; i++) {
      s[i] = b[i]-b[i+1];
   }
   for (int i = 0; i < n-1; i++) {
      ch[i] = a[i]-a[i+1];
   }
   w--;
   n--;
   int pr[w];
   pr[0] = 0;
   for (int i = 1; i < w; i++) {
      int j = pr[i-1];
      while (j && s[i] != s[j])
         j = pr[j-1];
      if (s[i] == s[j])
         j++;
      pr[i] = j;
   }
   int ans = 0;
   int j = 0;
   for (int i = 0; i < n; i++) {
      while (j && ch[i] != s[j])
         j = pr[j-1];
      if (ch[i] == s[j])
         j++;
      if (j == w) {
         ans++;
         j = pr[j-1];
      }
   }
   cout << ans;
}