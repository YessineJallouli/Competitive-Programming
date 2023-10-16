#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n; int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      for (int i = 0; i < n/2; i++) {
         cout << num[i] << ' ' << num[n-i-1] << ' ';
      }
      if (n%2)
         cout << num[n/2];
      cout << endl;
   }
}