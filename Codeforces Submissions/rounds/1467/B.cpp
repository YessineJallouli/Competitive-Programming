#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool t(int a, int b, int c) {
   if (b > a && b > c)
      return false;
   if (b < a && b < c)
      return false;
   return true;
}


int main ()
{
   ios_base::sync_with_stdio(false);
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int x = 0;
      bool virus[n];
      memset(virus, false, sizeof virus);
      bool two = false;
      bool three = false;
      for (int i = 1; i < n-1; i++) {
         if (num[i] > num[i+1] && num[i] > num[i-1]) {
            x++;
            virus[i] = true;
         }
         else if (num[i] < num[i+1] && num[i] < num[i-1]) {
            virus[i] = true;
            x++;
         }
      }
      for (int i = 1; i < n-1; i++) {
         if (virus[i] && virus[i+1] && virus[i-1]) {
            three = true;
         }
         if (virus[i] && virus[i+1]) {
            if (i+3 < n) {
               int b = num[i], c = num[i+1], d = num[i+2], e = num[i+3];
               if (t(b,d,e))
                  two = true;
            }
            if (i-2 >= 0) {
               int z = num[i-2], a = num[i-1], b = num[i], c = num[i+1];
               if (t(z,a,c))
                  two = true;
            }
            if (i+3 >= n || i-2 < 0)
               two = true;
         }
      }
      if (three) {
         cout << max(x-3,0) << endl;
      }
      else if (two)
         cout << max(x-2,0) << endl;
      else
         cout << max(x-1,0) << endl;
   }
}