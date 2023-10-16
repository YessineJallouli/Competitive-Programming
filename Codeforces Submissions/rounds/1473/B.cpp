#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      string s, s1;
      cin >> s >> s1;
      if (s.size() > s1.size())
         swap(s,s1);
      int n, n1;
      n = s.size();
      n1 = s1.size();
      int p = n*n1/__gcd(n,n1);
      string S = s;
      string S1 = s1;
      while (S.size() != p) {
         S+= s;
      }
      while (S1.size() != p) {
         S1+= s1;
      }
      if (S == S1) {
         cout << S << endl;
      }
      else
         cout << -1  << endl;
   }
}