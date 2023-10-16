#include <bits/stdc++.h>
using namespace std;

int main() {
   int n; cin >> n;
   int a[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   int b[n];
   for (int i = 0; i < n; i++) {
      b[i] = a[n-i-1];
   }
   int croissant[n];
   int decroissant[n];
   int nb = 1;
   for (int i = 0; i < n; i++) {
      if (i == n-1) {
         croissant[i] = nb;
         continue;
      }
      if (a[i] < a[i+1]) {
         croissant[i] = nb;
         nb++;
         continue;
      }
      croissant[i] = nb;
      nb = 1;
   }
   nb = 1;
   for (int i = 0; i < n; i++) {
      if (i == n-1) {
         decroissant[i] = nb;
         continue;
      }
      if (b[i] < b[i+1]) {
         decroissant[i] = nb;
         nb++;
         continue;
      }
      decroissant[i] = nb;
      nb = 1;
   }
   int dec[n];
   int cr[n];
   int mx = 0;
   for (int i = 0; i < n; i++) {
      dec[i] = decroissant[n-i-1];
      cr[i] = croissant[i];
      mx = max({dec[i], cr[i], mx});
   }
   int nb2 = 0;
   nb = 0;
   for (int i = 0; i < n; i++) {
      if (dec[i] == cr[i] && cr[i] == mx) {
         nb++;
      }
      if (dec[i] == mx)
         nb2++;
      if (cr[i] == mx)
         nb2++;
   }
   if (mx%2 == 1 && nb2 == 2 && nb == 1) {
      cout << 1;
   }
   else
      cout << 0;
}