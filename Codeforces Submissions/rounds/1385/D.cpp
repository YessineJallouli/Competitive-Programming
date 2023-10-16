#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int good(const string &s, char c, int n, int d) {
   if (n == 1)
   {
      if (s[d] == c)
         return 0;
      return 1;
   }
   int nb, nb1;
   nb = nb1 = 0;
   for (int i = d; i < d+n/2; i++)
      if (s[i] == c)
         nb++;
   for (int i = d+ n/2; i < d+n; i++)
      if (s[i] == c)
         nb1++;
   return min((n/2)-nb + good(s, c+1, n/2, d+n/2), (n/2)-nb1 + good(s, c+1, n/2, d));
}

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string s; cin >> s;
      cout << good(s, 'a', n, 0) << endl;
   }
}