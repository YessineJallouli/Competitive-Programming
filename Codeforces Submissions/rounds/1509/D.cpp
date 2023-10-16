#include <bits/stdc++.h>
using namespace std;


int nb(string &s, char c) {
   int n = s.size();
   int ans = 0;
   for (int i = 0; i < n; i++)
      if (s[i] == c)
         ans++;
   return ans;
}

void FO(string &a, string &b) {
   int n = a.size();
   if (nb(a, '1') > nb(b, '1')) {
      int nb = 0;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         if (b[i] == '0')
           nb++;
         else {
            v.push_back(nb);
            nb = 0;
         }
      }
      v.push_back(nb);
      int cnt = 0;
      int id = 0;
      for (int i = 0; i < n; i++) {
         if (a[i] == '1') {
            if (id != v.size()) {
               for (int j = 0; j < v[id]; j++) {
                  cout << '0';
                  cnt++;
               }
               id++;
            }
         }
         cnt++;
         cout << a[i];
      }
      if (id != v.size()) {
         for (int j = 0; j < v[id]; j++) {
            cout << '0';
            cnt++;
         }
      }
      while (cnt != (n/2*3)) {
         cnt++;
         cout << '0';
      }
   }
   else {
      int nb = 0;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         if (a[i] == '0')
           nb++;
         else {
            v.push_back(nb);
            nb = 0;
         }
      }
      v.push_back(nb);
      int cnt = 0;
      int id = 0;
      for (int i = 0; i < n; i++) {
         if (b[i] == '1') {
            if (id != v.size()) {
               for (int j = 0; j < v[id]; j++) {
                  cout << '0';
                  cnt++;
               }
               id++;
            }
         }
         cnt++;
         cout << b[i];
      }
      if (id != v.size()) {
         for (int j = 0; j < v[id]; j++) {
            cout << '0';
            cnt++;
         }
      }
      while (cnt != (n/2*3)) {
         cnt++;
         cout << '0';
      }
   }
}

void FZ(string &a, string &b) {
   int n = a.size();
   if (nb(a, '0') > nb(b, '0')) {
      int nb = 0;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         if (b[i] == '1')
           nb++;
         else {
            v.push_back(nb);
            nb = 0;
         }
      }
      v.push_back(nb);
      int cnt = 0;
      int id = 0;
      for (int i = 0; i < n; i++) {
         if (a[i] == '0') {
            if (id != v.size()) {
               for (int j = 0; j < v[id]; j++) {
                  cout << '1';
                  cnt++;
               }
               id++;
            }
         }
         cnt++;
         cout << a[i];
      }
      if (id != v.size()) {
         for (int j = 0; j < v[id]; j++) {
            cout << '1';
            cnt++;
         }
      }
      while (cnt != (n/2*3)) {
         cnt++;
         cout << '0';
      }
   }
   else {
      int nb = 0;
      vector<int> v;
      for (int i = 0; i < n; i++) {
         if (a[i] == '1')
           nb++;
         else {
            v.push_back(nb);
            nb = 0;
         }
      }
      v.push_back(nb);
      int cnt = 0;
      int id = 0;
      for (int i = 0; i < n; i++) {
         if (b[i] == '0') {
            if (id != v.size()) {
               for (int j = 0; j < v[id]; j++) {
                  cout << '1';
                  cnt++;
               }
               id++;
            }
         }
         cnt++;
         cout << b[i];
      }
      if (id != v.size()) {
         for (int j = 0; j < v[id]; j++) {
            cout << '1';
            cnt++;
         }
      }
      while (cnt != (n/2*3)) {
         cnt++;
         cout << '0';
      }
   }
}

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string a,b,c;
      cin >> a >> b >> c;
      int z1 = nb(a, '0'); int z2 = nb(b, '0'); int z3 = nb(c, '0');
      if (z1 >= n && z2 >= n)
         FZ(a,b);
      else if (z1 >= n && z3 >= n)
         FZ(a,c);
      else if (z2 >= n && z3 >= n)
         FZ(b,c);
      else {
         int o1 = nb(a, '1'); int o2 = nb(b, '1'); int o3 = nb(c, '1');
         if (o1 >= n && o2 >= n)
            FO(a,b);
         else if (o1 >= n && o3 >= n)
            FO(a,c);
         else
            FO(b,c);
      }
      cout << endl;
   }
}