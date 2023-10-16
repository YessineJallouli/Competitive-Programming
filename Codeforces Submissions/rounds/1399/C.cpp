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
//   2 2 2 2 2
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      map<int,int> nb;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         nb[num[i]]++;
      }
      sort(num, num+n);
      int ans = 0;
      for (int i = 2; i <= 2*n; i++) {
         int s = 0;
         for (int j = 1; j < min(n+1, i); j++) {
            int nn1 = nb[j];
            int nn2 = nb[i-j];
            s+= min(nn1, nn2);
         }
         s/=2;
         ans = max(ans, s);
      }
      cout << ans << '\n';
   }
}