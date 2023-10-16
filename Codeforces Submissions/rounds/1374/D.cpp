#include <bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(0) ;
   cin.tie(0) ;
   int T; cin >> T;
   while(T--) {
      long long n,k; cin >> n >> k;
      int num[n];
      for (int i = 0; i < n; i++) {
         int a; cin >> a;
         num[i] = (k-(a%k))%k;
      }
      sort(num, num+n);
      long long min_ans= 0;
      long long nb = 1;
      for (int i = 0; i < n; i++) {
         if (num[i] == 0)
            continue;
         if (i != n-1)
            if (num[i] == num[i+1]) {
               nb++;
               continue;
            }
         min_ans = max(num[i] + k*(nb-1), min_ans);
         nb = 1;
      }
      if (min_ans == 0)
         cout << 0 << '\n';
      else
         cout << min_ans+1 << '\n';
   }
}