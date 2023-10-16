#include <bits/stdc++.h>

using namespace std;

string inp;
char a1,a2;
int p,sz,sol;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    bool b = false;
    for (int i = 0; i < n; i++) {
       if (s[i] == 'R') {
          cout << i+1 << " "; b = true;
         break;
       }
    }
    if (! b) {
      for (int i = 0; i < n; i++) {
      if (s[i] == 'L' && s[i+1] == '.') {
         cout << i+1 << ' ';
         break;
      }
    }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == 'L') {
         cout << i;
         return 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == 'R' && s[i+1] == '.') {
         cout << i+2 << endl;
         return 0;
      }
    }


}