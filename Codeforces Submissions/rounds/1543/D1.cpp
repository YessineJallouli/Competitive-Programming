/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

bool query(int n) {
   cout << n << endl;
   int r; cin >> r;
   return r;
}

int main() {
   int T; cin >> T;
   while (T--) {
      int n, k; cin >> n >> k; n--;
      for (int i = 0; i <= n; i++) {
         if (i == 0)
            query(i);
         else {
            int ss = i^(i-1);
            query(ss);
         }
      }
   }
}