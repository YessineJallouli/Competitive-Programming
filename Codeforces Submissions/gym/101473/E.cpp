#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int N, R; cin >> N >> R;
   bool m[N+1];
   memset(m, false, sizeof m);
   for (int i = 0; i < R; i++) {
      int x; cin >> x;
      m[x] = true;
   }
   for (int i = 1; i <= N; i++) {
      if (!m[i]) {
         cout << i << ' ';
      }
   }
   if (N == R)
      cout << '*';
}