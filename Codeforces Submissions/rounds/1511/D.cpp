#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int n,k; cin >> n >> k;
   string s = "";
   for (char c = 'a'; c < 'a' + k; c++) {
      s+= c;
      for (char c1 = c+1; c1 < 'a'+k; c1++) {
         s+= c; s+= c1;
      }
   }
   for (int i = 0; i < n; i++)
      cout << s[i%s.size()];
}