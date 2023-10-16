#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      if (n == 0)
         cout << 0 << endl;
      else {
         int I = n-1;
         int K = 0;
         while (true) {
           if (I == 0)
              break;
           if (num[I] == num[I-1])
              K++;
           else
              break;
           I--;
         }
         if (num[I] > num[I-1]) {
            int id = -1;
            int nb = K;
            for (int i = I-1; i > 0; i--) {
               if (num[i-1] > num[i]) {
                  id = i;
                  break;
               }
               nb++;
            }
            cout << max(n-(nb+2),0) << '\n';
         }
         else {
            int id = -1;
            int nb = K;
            for (int i = I-1; i > 0; i--) {
               if (num[i-1] < num[i]) {
                  id = i;
                  break;
               }
               nb++;
            }
            for (int i = id; i >= 0; i--) {
               if (num[i-1] > num[i]) {
                  break;
               }
               nb++;
            }
            cout << max(n-(nb+2),0) << '\n';
         }
      }

   }
}