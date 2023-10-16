#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      vector<int> l;
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         if (x == 1) {
            l.push_back(x);
         }
         else {
            while (l.size() != 0) {
               if (l.back() != x-1)
                  l.pop_back();
               else {
                  l.pop_back();
                  l.push_back(x);
                  break;
               }
            }
         }
         for (int j = 0; j < l.size()-1; j++)
            cout << l[j] << '.';
         cout << l.back() << endl;
      }
   }
}