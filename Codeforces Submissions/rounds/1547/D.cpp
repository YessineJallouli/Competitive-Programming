/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int manip(int a, int b) {
   int a1 = a;
   for (int i = 1; i <= a; i*= 2) {
      if ((a & i) && (b & i)) {
         a1-= i;
      }
   }
   return a1;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int ans[n];
      cout << 0 << ' ';
      ans[0] = num[0];
      for (int i = 1; i < n; i++) {
         int b = manip(ans[i-1], num[i]);
         cout << b << ' ';
         ans[i] = (b^num[i]);
      }
      cout << endl;
   }
}