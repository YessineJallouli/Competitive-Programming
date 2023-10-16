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
   while (T--) {
      int n; cin >> n;
      int k = n/2;
      if (k % 2 == 1) {
         cout << "NO" << endl;
         continue;
      }
      cout << "YES" << endl;
      int h = 2;
      int s = 0;
      for (int i = 0; i < k; i++) {
         cout << h << ' ' ;
         s+= h;
         h+= 2;
      }
      int t = 1;
      int s1 = 0;
      for (int i = 0; i < k-1; i++) {
         cout << t << ' ' ;
         s1+= t;
         t+=2;
      }
      cout << s-s1 << endl;
   }
}