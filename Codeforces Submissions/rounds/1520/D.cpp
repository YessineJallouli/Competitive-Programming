#include "bits/stdc++.h"
using namespace std;
// Hi

int main(){
   ios::sync_with_stdio(0);cin.tie(0);
   int tt;
   cin>>tt;
   while(tt--){
      int n; cin >> n;
      int num[n];
      map<long long,long long> nb;
      set<long long> s;
      for (int i = 0; i < n; i++) {
         int x; cin >> x;
         num[i] = x-i;
         nb[num[i]]++;
         s.insert(num[i]);
      }
      long long ans = 0;
      for (int i : s) {
         ans+= nb[i]*(nb[i]-1)/2;
      }
      cout << ans << endl;

   }
   return 0;
}