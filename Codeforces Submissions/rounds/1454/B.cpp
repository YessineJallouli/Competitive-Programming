#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      map<int,int> nb;
      int mn = n;
      for (int i= 0; i < n; i++) {
         cin >> num[i];
         nb[num[i]]++;
         //mn = min(nb[num[i], mn);
      }
      int ans = -1;
      int mn2 = n;
      for (int i = 0; i < n; i++) {
         if (nb[num[i]] == 1 && num[i] <= mn2) {
            mn2 = num[i];
            ans = i+1;
         }
      }
      cout << ans << endl;
   }
}