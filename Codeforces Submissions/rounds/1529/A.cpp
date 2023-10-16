#include <bits/stdc++.h>
#define ll long long

using namespace  std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i <n; i++)
         cin >> num[i];
      int ans = 0;
      sort(num, num+n);
      for (int i = 0; i <n; i++) {
         if (num[i] != num[0])
            ans++;
      }
      cout << ans << endl;
   }
}