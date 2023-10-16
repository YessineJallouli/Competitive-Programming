#include<bits/stdc++.h>
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
      int n, m;
      cin >> n >> m;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++)
         {
            if (i == n-1 && j == m-1)
               cout << 'W';
            else
               cout << 'B';
         }
         cout << endl;
      }
   }
}