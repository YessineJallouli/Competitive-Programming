#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   //reopen("triangulos.c", "r", stdin);
   int N; cin >> N;
   int a[N];
   for (int i = 0; i < N; i++) {
      cin >> a[i];
   }
   int prefix[N];
   prefix[0] = a[0];
   map<int,int> m;
   m[prefix[0]] = 0;
   for (int i = 1; i < N; i++) {
      prefix[i] = prefix[i-1] + a[i];
      m[prefix[i]] = true;
   }
   if (prefix[N-1]%3) {
      cout << 0;
      return 0;
   }
   int b = prefix[N-1]/3;
   int ans = 0;
   for (int i = 0; i < N; i++) {
      int p1 = (prefix[i]+b)%(prefix[N-1]);
      int p2 = prefix[i]-b;
      if (p2 < 0) {
         p2+= prefix[N-1];
      }
      if (m[p1] && m[p2]) {
         ans++;
         m[p1] = false;
         m[p2] = false;
      }
   }
   cout << ans;
}