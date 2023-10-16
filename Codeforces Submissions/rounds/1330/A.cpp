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
   int T; cin >> T;
   while (T--)
   {
      int n, x; cin >> n >> x;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      sort(num, num+n);
      int nb = 1;
      for (int i = 0; i < n; i++)
      {
         if (num[i] == nb)
         {
            nb++;
            continue;
         }
         while (num[i] > nb && x > 0)
         {
            nb++;
            x--;
         }
         if (num[i] == nb)
            nb++;
      }
      cout << nb+x-1 << endl;
   }
}