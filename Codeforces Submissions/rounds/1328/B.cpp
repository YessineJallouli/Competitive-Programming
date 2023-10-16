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
   while (t--)
   {
      int n, k; cin >> n >> k;
      int nb = 1;
      int num = 1;
      while (num < k)
      {
         num+= nb+1;
         nb++;
      }
      int pos2 = n-1-nb;
      int pos1 = num-k + pos2+1;
      for (int i = 0; i < n; i++)
      {
         if (i == pos1 || i == pos2)
            cout << 'b';
         else
            cout << 'a';
      }
      cout << endl;
   }
}