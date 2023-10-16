#include<bits/stdc++.h>
#define MOD 1e9+7
#define ull long long
#define ll unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int T; cin >> T;
   map<int, bool> p2;
   int n = 1;
   while (n < 1e9) {
      n*= 2;
      p2[n-1] = true;
   }

   while (T--) {
      int n; cin >> n;
      if (p2[n])
      {
         cout << 1 << endl;
         continue;
      }
      for (int i = 2; i <= sqrt(n); i++) {
         if (n%i == 0) {
            int h = n/i;
            if (p2[h]) {
                cout << i << endl;
                break;
            }
            if (p2[i]) {
               cout << h << endl;
               break;
            }
         }
      }
   }
}