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
      int num[n+1];
      for (int i = 1 ;i <= n; i++)   {
         cin >> num[i];
      }
      sort(num+1, num+n+1);
      int maxi = 0;
      int nb = 0;
      for (int i = n; i >= 1; i--) {
         nb++;
         maxi = max(maxi, min(nb, num[i]));
      }
      cout << maxi << endl;
   }
}