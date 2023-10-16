#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool D(string &s) {
   int diff = 0;
   for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
         diff++;
      else
         diff--;
      if (diff < 0)
         return 0;
   }
   if (diff != 0)
      return 0;
   return 1;
}


int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      if (s[0] != '1' || s[n-1] != '1') {
         cout << "NO" << endl;
         continue;
      }
      string a = "";
      string b = "";
      int d1 = 0;
      int d2 = 0;
      int nb1 = 0;
      int nb2 = 0;
      for (int i = 0; i < n; i++) {
         //cout << d1 << ' ' << d2 << endl;
         if (s[i] == '0') {
            if (nb1 == n/2 && nb2 < n/2) {
               a+= ')';
               b+= '(';
               d1--;
               d2++;
               nb2++;
            }
            else if (nb2 == n/2 && nb1 < n/2) {
               a+= '(';
               b+= ')';
               d1++;
               d2--;
               nb1++;
            }
            else if (d2 == 0) {
               a+= ')';
               b+= '(';
               d1--;
               d2++;
               nb2++;
            }
            else if (d1 == 0) {
               a+= '(';
               b+= ')';
               d1++;
               d2--;
               nb1++;
            }
            else {
               if (d1 > d2) {
                  a+= ')';
                  b+= '(';
                  d1--;
                  d2++;
                  nb2++;
               }
               else {
                  a+= '(';
                  b+= ')';
                  d1++;
                  d2--;
                  nb1++;
               }
            }
         }
         else {
            if (nb1 == n/2 || nb2 == n/2) {
               a+= ')';
               b+= ')';
               d1--;
               d2--;
            }
            else if (d1 == 0 || d2 == 0) {
               a+= '(';
               b+= '(';
               d1++;
               d2++;
               nb1++;
               nb2++;
            }
            else {
               if (i != n-1) {
                  if (d1 == 1 && d2 == 1 && s[i+1] == '0') {
                     a+= '(';
                     b+= '(';
                     nb1++;
                     nb2++;
                     d1++;
                     d2++;
                  }
                  else {
                     a+= ')';
                     b+= ')';
                     d1--;
                     d2--;
                  }
               }
               else {
                  a+= ')';
                  b+= ')';
                  d1--;
                  d2--;
               }
            }
         }
      }
      if (D(a) && D(b)) {
         cout << "YES" << endl;
         cout << a << endl << b << endl;
      }
      else
         cout << "NO" << endl;
   }
}