#include <bits/stdc++.h>
using namespace std;

const int mx = 1e7+1;
int sieve[mx];
int mindiv[6*mx];

int main()
{
   memset(sieve, -1, sizeof sieve);
   memset(mindiv, -1, sizeof mindiv);
   for (int i = 2; i < mx; i++) {
      if (sieve[i] == -1) {
         for (int j = i; j < mx; j+= i) {
            if (sieve[j] == -1)
               sieve[j] = i;
         }
      }
   }
   for (int i = 2; i < mx; i++) {
      int a = i;
      int prev = sieve[a];
      int sum = 1;
      int p = 1;
      int ans = 1;
      while (a != 1) {
         int x = sieve[a];
         a/= x;
         if (x == prev) {
            p*= x;
            sum+= p;
         }
         else {
            ans*= sum;
            prev = x;
            p = x;
            sum = 1+x;
         }
      }
      ans*= sum;
      if (mindiv[ans] == -1)
         mindiv[ans] = i;
   }
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n == 1)
         cout << 1 << endl;
      else
         cout << mindiv[n] << endl;
   }
}