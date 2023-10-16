#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      sort(num, num+n);
      vector<int> ans;
      ans.push_back(num[n-1]);
      int gcd = num[n-1];
      num[n-1] = -1;
      for (int i = 1; i < n; i++) {
         int mx = 0;
         int id = -1;
         for (int j = 0; j < n; j++) {
            if (num[j] == -1)
               continue;
            if (__gcd(num[j], gcd) > mx) {
               mx = __gcd(num[j], gcd);
               id = j;
            }
         }
         gcd = mx;
         ans.push_back(num[id]);
         num[id] = -1;
      }
      for (int i : ans)
         cout << i << ' ';
      cout << endl;
   }
}