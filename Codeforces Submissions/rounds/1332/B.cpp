#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;
bool prime(int n) {
   if (n < 2)
      return false;
   for (int i = 2; i <= sqrt(n); i++)
      if (n%i == 0)
         return false;
   return true;
}

int main()
{
   vector<int> p;
   for (int i = 2; i <= 1000; i++)
      if (prime(i))
         p.push_back(i);

   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      int color[n] = {0};
      unordered_map<int, vector<int>> mapa;
      for (int i = 0; i < n; i++) cin >> num[i];
      for (int i = 0; i < n; i++)
      {
         for (int t : p)
            if (num[i] % t == 0)
               mapa[t].push_back(i);
      }
      int nb = 1;
      for (int t : p) {
         if (mapa[t].size() != 0)
         {
            bool b = false;
            for (int i = 0; i < mapa[t].size(); i++)
               if (color[mapa[t][i]] == 0)
               {
                  color[mapa[t][i]] = nb;
                  b = true;
               }
            if (b) nb++;
         }
      }
      cout << nb-1 << endl;
      for (int i = 0; i < n; i++)
         cout << color[i] << ' ';
      cout << endl;
   }

}