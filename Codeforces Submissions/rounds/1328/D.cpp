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
   int q; cin >> q;
   while (q--) {
      int n; cin >> n;
      int num[n];
      int color[n];
      int maxi = 1;
      for (int i = 0; i < n; i++)
         cin >> num[i];
      color[0] = 1;
      for (int i = 1; i < n; i++)
      {
         if (num[i] == num[i-1])
            color[i] = color[i-1];
         else
         {
            if (color[i-1] == 1)
            {
                color[i] = 2;
                maxi = 2;
            }
            else
               color[i] = 1;
         }
      }
      if (color[0] == color[n-1] && num[0] != num[n-1])
      {
         bool eq = false;
         for (int i = 1; i < n; i++)
         {
            if (num[i] == num[i-1] && !eq)
            {
               eq = true;
               if (color[i] == 1)
                  color[i] = 2;
               else
                  color[i] = 1;
               for (int k = i+1; k < n; k++)
               {
                  if (num[k] == num[k-1])
                     color[k] = color[k-1];
                  else
                  {
                     if (color[k-1] == 1)
                        color[k] = 2;
                     else
                        color[k] = 1;
                  }
               }
            }
         }
         if (!eq)
         {
            color[n-1] = 3;
            maxi = 3;
         }
      }
      cout << maxi << endl;
      for (int i = 0; i < n; i++)
         cout << color[i] << ' ';
      cout << endl;
   }
}