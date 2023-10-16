#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PI 4*atan(1)
using namespace std;

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      ll num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      ll ans = 0;
      ll sum = 0;
      for (int i = n-1; i >= 0; i--){
         sum+= num[i];
         if (sum > 0)
            ans = max(ans, sum);
      }
      cout << ans << endl;
   }
}