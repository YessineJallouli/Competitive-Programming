#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n;
      cin >> n;
      int num[n];
      int kk[n];
      map<int,int> nb;
      int mn = n+1;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         kk[i] = num[i];
         if (i == 0) {
            nb[num[i]]++;
         }
         if (i != 0) {
            if (num[i] != num[i-1])
               nb[num[i]]++;
         }
      }
      for (int i = 0; i < n; i++) {
         mn = min(mn, nb[num[i]]);
      }
      sort(kk, kk+n);
      if (kk[0] == kk[n-1])
      {
         cout << 0 << endl;
         continue;
      }
      int ans = mn;
      if (nb[num[0]] != mn && nb[num[n-1]] != mn) {
         ans = mn+1;
      }
      else if (nb[num[0]] == mn && nb[num[n-1]] == mn && num[0] == num[n-1]) {
         ans = mn-1;
      }
      else
         ans = mn;
      mn++;
      int ans1 = mn;
      if (nb[num[0]] != mn && nb[num[n-1]] != mn) {
         ans1 = mn+1;
      }
      else if (nb[num[0]] == mn && nb[num[n-1]] == mn && num[0] == num[n-1]) {
         ans1 = mn-1;
      }
      else
         ans1 = mn;
      cout << min(ans, ans1) << endl;
   }
}