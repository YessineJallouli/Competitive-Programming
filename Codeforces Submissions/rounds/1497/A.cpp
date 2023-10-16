#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SAVETIME ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
   SAVETIME
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      set<int> s;
      map<int,int> nb;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         s.insert(num[i]);
         nb[num[i]]++;
      }
      for (int i : s) {
         cout << i << ' ';
      }
      for (int i : s) {
         for (int ii = 0; ii < nb[i]-1; ii++)
            cout << i << ' ';
      }
      cout << endl;
   }
}