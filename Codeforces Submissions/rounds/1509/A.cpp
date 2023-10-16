#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      vector<int> v;
      for (int i=  0; i < n; i++) {
         if (num[i]%2)
            v.push_back(num[i]);
      }
      for (int i=  0; i < n; i++) {
         if (num[i]%2 == 0)
            v.push_back(num[i]);
      }
      for (int i : v)
         cout << i << ' ';
      cout << endl;
   }
}