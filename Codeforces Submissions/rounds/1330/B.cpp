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
   SaveTime
   int T; cin >> T;
   while (T--)
   {
      int n; cin >> n;
      vector<int> num;
      for (int i = 0; i < n; i++) {
         int h; cin >> h;
         num.push_back(h);
      }
      unordered_map<int, bool> p;
      unordered_map<int, bool> perfect;
      vector<int> v;
      int fin = 1;
      for (int i = 0; i < n; i++)
      {
         int k = num[i];
         if (p[k])
            break;
         p[k] = true;
         if (k >= (i+1) && k > fin)
            fin = k;
         if (i+1 == fin)
            perfect[i+1] = true;
      }
      reverse(num.begin(), num.end());
      p.clear();
      fin = 1;
      int nb = 0;
      for (int i = 0; i < n; i++)
      {
         int k = num[i];
         if (p[k])
            break;
         p[k] = true;
         if (k >= (i+1) && k > fin)
            fin = k;
         if (i+1 == fin)
         {
            if (perfect[n-i-1]) {
               v.push_back(n-i-1);
               nb++;
            }
         }
      }
      cout << nb << endl;
      for (int i : v)
         cout << i << ' ' << n-i << endl;
      num.clear();
      v.clear();
      p.clear();
   }
}