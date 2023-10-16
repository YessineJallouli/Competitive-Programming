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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int a[n], b[n];
      memset(b, 0, sizeof b);
      bool v[n+1];
      memset(v, false, sizeof v);
      vector<int> vide;
      vector<int> num;
      for (int i = 0; i < n; i++) {
         cin >> a[i];
         if (a[i] != (i+1) && v[a[i]] == false) {
            v[a[i]] = true;
            b[i] = a[i];
         }
         else {
            vide.push_back(i+1);
         }
      }
      for (int i = 1; i <= n; i++) {
         if (v[i] == false)
            num.push_back(i);
      }
      if (vide.size() == 1 && num.size() == 1) {
         if (vide[0] == num[0]) {
            num.clear();
            memset(v, false, sizeof v);
            memset(b, 0, sizeof b);
            vide.clear();
            for (int i = n-1; i >= 0; i--) {
               if (a[i] != (i+1) && v[a[i]] == false) {
                  v[a[i]] = true;
                  b[i] = a[i];
               }
               else {
                  vide.push_back(i+1);
               }
            }
            for (int i = 1; i <= n; i++) {
               if (v[i] == false)
                  num.push_back(i);
            }
         }
      }
      map<int,int> m;
      for (int i : vide) {
         m[i] = true;
      }
      vector<int> com;
      for (int i : num) {
         if (m[i])
            com.push_back(i);
      }
      if (com.size() == vide.size() && vide.size() != 0) {
         sort(vide.begin(), vide.end());
         num.clear();
         num.push_back(vide.back());
         for (int i = 0; i < vide.size()-1; i++)
            num.push_back(vide[i]);
      }
      else {
         vector<int> vide1;
         vector<int> num1;
         map<int,int> m1;
         for (int i : com) {
            m1[i] = true;
         }
         for (int i : num) {
            if (! m[i]) {
               num1.push_back(i);
               m1[i] = true;
               break;
            }
         }
         for (int i : com) {
            num1.push_back(i);
            vide1.push_back(i);
         }
         for (int i : num) {
            if (! m1[i])
               num1.push_back(i);
         }
         for (int i : vide) {
            if (!m1[i])
               vide1.push_back(i);
         }
         vide.swap(vide1);
         num.swap(num1);
      }
      for (int i = 0; i < vide.size(); i++) {
         b[vide[i]-1] = num[i];
      }
      cout << n-vide.size() << endl;
      for (int i = 0; i < n; i++)
         cout << b[i] << ' ';
      cout << endl;
   }
}