#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; scanf("%d", &n);
      map<int,int> nb;
      bool ans = false;
      for (int i = 0; i < n; i++) {
         int x; scanf("%d", &x);
         nb[x]++;
         if (nb[x] > 1)
            ans = true;
      }
      if (ans)
         printf("yes\n");
      else
         printf("no\n");
   }
}