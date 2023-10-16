#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      string s; cin >> s;
      string a = "", b = "";
      bool ga = false;
      bool eq = true;
      for (int i = 0; i < n; i++) {
         if (s[i] == '2')
         {
            if (eq) {
               a+= '1';
               b+= '1';
            }
            else if (ga) {
               a+= '0';
               b+= '2';
            }
            else {
               a+= '2';
               b+= '0';
            }
         }
         else if (s[i] == '1')
         {
            if (ga)
            {
               a+= '0';
               b+= '1';
            }
            else if (eq)
            {
               eq = false;
               ga = true;
               a+= '1';
               b+= '0';
            }
         }
         else
         {
            a+= '0';
            b+= '0';
         }
      }
      cout << a << endl << b << endl;
   }
}