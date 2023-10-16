#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define PI 4*atan(1)
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         int a; cin >> a;
         v.push_back(a);
      }
      reverse(v.begin(), v.end());
      for (int i : v)
         cout << i << ' ';
      cout << endl;
   }
}