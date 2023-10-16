#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
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
      int nb = 0;
      int K[n+1] = {0};
      int maxi = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         K[num[i]]++;
         if (K[num[i]] == 1)
            nb++;
         maxi = max(K[num[i]], maxi);
      }
      if (n == 1)
         cout << 0 << endl;
      else
         cout << max(min(nb-1, maxi), min(maxi-1, nb))<< endl;
   }
}