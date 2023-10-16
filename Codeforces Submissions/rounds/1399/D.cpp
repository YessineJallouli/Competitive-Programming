#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   //1110000
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      int belong[n];
      char c = s[0];
      memset(belong, 0, sizeof belong);
      int nb = 1;
      int ans = 1;
      vector<int> one;
      vector<int> zero;
      for (int i = 0; i < n; i++) {
         if (s[i] == '1')
         {
            if (zero.size() == 0) {
               one.push_back(nb);
               belong[i] = nb;
               nb++;
            }
            else {
               belong[i] = zero.back();
               one.push_back(zero.back());
               zero.pop_back();
            }
         }
         else {
            if (one.size() == 0) {
               belong[i] = nb;
               zero.push_back(nb);
               nb++;
            }
            else {
               belong[i] = one.back();
               zero.push_back(one.back());
               one.pop_back();
            }
         }
      }
      cout << nb-1 << '\n';
      for (int i : belong)
         cout << i << ' ' ;
      cout << '\n';
   }
}