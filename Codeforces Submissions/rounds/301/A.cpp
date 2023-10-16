#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int n; cin >> n;
   int a[2*n-1]; int sum = 0, nb = 0;
   bool z = false;
   for (int i = 0; i < 2*n-1; i++) {
      cin >> a[i];
      sum+= abs(a[i]);
      if (a[i] < 0)
         nb++;
      if (a[i] == 0)
         z = true;
   }
   sort(a, a+2*n-1);
   int neg = INT_MAX;
   for (int i = 0; i < 2*n-1; i++)
      neg = min(neg, abs(a[i]));
   if (nb%2 == 0 || z || n%2 == 1)
      cout << sum;
   else
      cout << sum - 2*neg;
}