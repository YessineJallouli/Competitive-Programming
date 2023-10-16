#include <bits/stdc++.h>
#define ll long long
using namespace std;

string t(int id, string &s) {
   string ch = "";
   for (int i = 0; i < s.size(); i++) {
      if (i == id) {
         ch+= "a";
      }
      ch+= s[i];
   }
   if (id == s.size())
      ch+='a';
   return ch;
}

int main() {
   int T; cin >> T;
   while (T--) {
      string s; cin >> s;
      int n = s.size();
      bool b = true;
      for (int i = 0; i < n; i++) {
         if (s[i] != 'a') {
            b = false;
            cout << "YES" << endl;
            cout << t(n-i, s) << endl;
            break;
         }
      }
      if (b) {
         cout << "NO" << endl;
      }
   }
}