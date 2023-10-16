#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> b;

bool split(vector<int> v) {
   if (v.size() < b.size())
      return false;
   if (v.size() == b.size()) {
      bool an1 = true;
      bool an2 = true;
      for (int i = 0; i < b.size(); i++) {
         if (v[i] != b[i])
            an1 = false;
         if (v[i] != b[b.size()-i-1])
            an2 = false;
      }
      return an1||an2;
   }
   bool ans = false;
   int len = v.size();
   for (int i = 1; i < len; i++) {
      vector<int> v1;
      if (2*i-1 < len) {
         for (int j = len-1; j >= 2*i; j--)
            v1.push_back(v[j]);
         for (int j = 0; j < i; j++)
            v1.push_back(v[j]+v[2*i-j-1]);
      }
      else {
         int fin = 2*i-len;
         for (int j = 0; j < fin; j++) {
            v1.push_back(v[j]);
         }
         for (int j = fin; j < fin+len-j-1; j++)
            v1.push_back(v[j] + v[fin+len-j-1]);
      }
      ans = ans|| split(v1);
   }
   return ans;
}

int main() {
   int n; cin >> n;
   vector<int> v;
   for (int i = 0; i < n; i++) {
      int x; cin >> x;
      v.push_back(x);
   }
   int m; cin >> m;
   for (int i = 0; i < m; i++) {
      int x; cin >> x;
      b.push_back(x);
   }
   if (split(v)) {
      cout << "S";
   }
   else
      cout << "N";
}