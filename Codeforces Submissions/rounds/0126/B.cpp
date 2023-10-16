/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   string s; cin >> s;
   int n = s.size();
   vector<int> pr(n);
   pr[0] = 0;
   for (int i = 1; i < n; i++) {
      int j = pr[i-1];
      while (j > 0 && s[j] != s[i])
         j = pr[j-1];
      if (s[i] == s[j])
         j++;
      pr[i] = j;
   }
   if (pr[n-1] == 0) {
      cout << "Just a legend";
      return 0;
   }
   for (int i = 1; i < n-1; i++) {
      if (pr[i] == pr[n-1]) {
         cout << s.substr(0, pr[i]);
         return 0;
      }
   }
   string sf = s.substr(n-pr[n-1], pr[n-1]);
   int n1 = sf.size();
   vector<int> pr1(n1);
   pr1[0] = 0;
   for (int i = 1; i < n1; i++) {
      int j = pr1[i-1];
      while (j > 0 && sf[j] != sf[i])
         j = pr1[j-1];
      if (sf[i] == sf[j])
         j++;
      pr1[i] = j;
   }
   if (pr1[n1-1] == 0) {
      cout << "Just a legend";
   }
   else
      cout << s.substr(0, pr1[n1-1]);
}