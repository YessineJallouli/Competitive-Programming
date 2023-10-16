#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   freopen("lis.in", "r", stdin);
   string s; cin >> s;
   bool b = true;
   for (int i = 1; i < s.size(); i++)
      if (s[i] != '9')
         b = false;
   if (b) {
      cout << s[0]-'0' + 9*(s.size()-1) << endl;
   }
   else
      cout << s[0]-'0'-1 + 9*(s.size()-1) << endl;
}