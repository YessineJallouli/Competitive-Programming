/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int sort_permutation_with_swap(vector<int>&p) {
   int N = p.size();
   int visite[N+1];
   memset(visite, false, sizeof visite);
   int ans = 0;
   for (int i = 0; i < N; i++) {
      if (p[i] == i+1)
         continue;
      if (visite[p[i]])
         continue;
      int sizeofcycle = 0;
      int x = p[i];
      while (!visite[x]) {
         visite[x] = true;
         x = p[x-1];
         sizeofcycle++;
      }
      ans+=(sizeofcycle-1);
   }
   return ans;
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n,m; cin >> n >> m;
      int pos[n+1];
      int num[n];
      for (int i = 1; i <= n; i++) {
         int x; cin >> x;
         num[i-1] = x;
         pos[x] = i;
      }
      int dec[n+1];

      for (int i = 1; i <= n; i++) {
         dec[i] = pos[i]-i;
         if (dec[i] < 0) {
            dec[i]+= n;
         }
      }
      map<int,int> nb;
      for (int i = 1; i <= n; i++) {
         nb[dec[i]]++;
      }
      set<int> s;
      for (int i = 1; i <= n; i++) {
         s.insert(dec[i]);
      }
      vector<int> ans;
      for (int i : s) {
         int cnt = nb[i];
         int res = n-cnt;
         if ((res+1)/2 > m)
            continue;
         else {
            vector<int> cyclic;
            int decalage = n-i;
            for (int j = n-decalage; j < n; j++) {
               cyclic.push_back(num[j]);
            }
            for (int j = 0; j < n-decalage; j++) {
               cyclic.push_back(num[j]);
            }
            /*cout << decalage << endl;
            for (int j : cyclic)
               cout << j << ' ';
            cout << endl;*/
            int perm = sort_permutation_with_swap(cyclic);
            if (perm <= m)
               ans.push_back(i);
         }
      }
      cout << ans.size() << ' ';
      for (int i : ans) {
         cout << i << ' ';
      }
      cout << endl;
   }
}