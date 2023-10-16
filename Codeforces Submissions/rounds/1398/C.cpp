#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      map<int,int> cnt;
      cnt[0] = 1;
      int num[n];
      for (int i = 0; i < n; i++) num[i] = s[i]-'0'-1;
      ll ans = 0;
      ll sum = 0;
      for (int i = 0; i < n; i++) {
         sum+= num[i];
         ans+= cnt[sum];
         cnt[sum]++;
      }
      cout << ans << endl;
   }
}