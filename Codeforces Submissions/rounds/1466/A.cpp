#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      set<int> s;
      for (int i = 0; i < n; i++) {
         for (int j = i+1; j < n; j++) {
            s.insert(abs(num[i]-num[j]));
         }
      }
      cout << s.size() << endl;
      s.clear();
   }
}