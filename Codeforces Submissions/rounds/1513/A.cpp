#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n,k; cin >> n >> k;
      if (k > (n-1)/2) {
         cout << -1 << endl;
      }
      else {
         int num[n];
         memset(num, 0, sizeof num);
         int nb = 0;
         int a = n;
         for (int i = 1; nb < k; i+=2) {
            num[i] = a;
            a--;
            nb++;
         }
         a = 1;
         for (int i = 0; i < n; i++) {
            if (num[i] == 0) {
               num[i] = a;
               a++;
            }
         }
         for (int i = 0; i < n; i++)
            cout << num[i] << ' ';
         cout << endl;
      }
   }
}