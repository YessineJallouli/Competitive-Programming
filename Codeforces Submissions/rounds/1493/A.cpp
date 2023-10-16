#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k;
      vector<int> v;
      for (int i = n; i > k; i--) {
         v.push_back(i);
      }
      for (int i = k-1; i*2 >= k; i--) {
         v.push_back(i);
      }
      cout << v.size() << endl;
      for (int x : v)
         cout << x <<  ' ';
      cout << endl;
   }
}