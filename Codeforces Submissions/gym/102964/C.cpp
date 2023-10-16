#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int n; cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a, a+n);
   int ans[n];
   int id = 1;
   int kk;
   for (int i = n-1; i >= 0; i--) {
      if (id >= n) {
         kk = i;
         break;
      }
      ans[id] = a[i];
      id+= 2;
   }
   id = 0;
   for (int i = kk; i >= 0; i--) {
      if (id >= n)
         break;
      ans[id] = a[i];
      id+= 2;
   }
   bool b = true;
   for (int i = 0; i < n; i++) {
      if (ans[i] == ans[i+1])
         b = false;
   }
   if (!b) {
      cout << -1;
   }
   else {
      for (int i = 0; i < n; i++)
         cout << ans[i] << ' ';
   }
}