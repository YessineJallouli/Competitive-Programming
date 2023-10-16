#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool verify(int a,int b, int c) {
   return (((a >= b) && (b >= c)) || ((a <= b) && (b <= c)));
}

int main() {
   int T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      ll sum = n*(n+1)/2;
      for (int i = 2; i < n; i++) {
         if (verify(num[i], num[i-1], num[i-2])) {
            sum-= (i-1);
            continue;
         }
         if (i == 2) {
            continue;
         }
         if (verify(num[i], num[i-1], num[i-3]) || verify(num[i], num[i-2], num[i-3])) {
            sum-= (i-2);
         }
         else if (verify(num[i-1], num[i-2], num[i-3]))
            sum-= (i-2);
         else if (i > 3)
            sum-= (i-3);
      }
      cout << sum << endl;
   }
}