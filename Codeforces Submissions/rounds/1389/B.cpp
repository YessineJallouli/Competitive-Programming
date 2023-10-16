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
      int ans = 0;
      int n, k, z; cin >> n >> k >> z;
      int num[n];
      for (int i=  0; i < n; i++)
         cin >> num[i];
      for (int i = 0; i <= z; i++) {
         int id = k- 2*i;
         int sum = 0;
         int sum_maxi = 0;
         for (int h = 0; h <= id; h++) {
            if (h < n-1)
               sum_maxi = max(sum_maxi, num[h]+num[h+1]);
            sum+= num[h];
         }
         ans = max(ans, sum+sum_maxi*i);
      }
      cout << ans << '\n';
   }
}