#include "bits/stdc++.h"
using namespace std;


void query(int a, int b) {
   cout << "?" << ' ' << a << ' ' << b << endl;
   cout.flush();
}

int main(){
   int n, t; cin >> n >> t;
   int k; cin >> k;
   int d = 1, f = n;
   int ans;
   while (d <= f) {
      int mid = (f+d)/2;
      query(1,mid);
      int x; cin >> x;
      if (mid-x < k) {
         d = mid+1;
      }
      else {
         f = mid-1;
         ans = mid;
      }
   }
   cout << "! " << ans;
   return 0;
}