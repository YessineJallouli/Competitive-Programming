#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      deque<int> T;
      deque<int> M;
      string s; cin >> s;
      bool ans = true;
      int diff = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'T') {
            diff++;
         }
         else {
            diff--;
         }
         if (diff < 0)
            ans = false;
      }
      reverse(s.begin(), s.end());
      diff = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == 'T') {
            diff++;
         }
         else {
            diff--;
         }
         if (diff < 0)
            ans = false;
      }
      int x = n/3;
      if (!ans)
         cout << "NO" << endl;
      else if (diff != x) {
         cout << "NO" << endl;
      }
      else
         cout << "YES" << endl;
   }
}