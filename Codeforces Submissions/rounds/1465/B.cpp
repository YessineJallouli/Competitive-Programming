#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      ll n; cin >> n;
      vector<int> v;
      while (true) {
         bool ans = true;
         ll N = n;
         while (N != 0) {
            if (N%10)
               v.push_back(N%10);
            N/= 10;
         }
         for (int i : v) {
            if (n%i != 0) {
               ans = false;
               break;
            }
         }
         if (ans) {
            cout << n << endl;
            break;
         }
         else {
            n++;
         }
         v.clear();
      }
   }
}