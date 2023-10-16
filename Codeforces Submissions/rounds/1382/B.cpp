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
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      int nb = 0;
      for (int i = 0; i < n; i++) {
         if (num[i] == 1)
            nb++;
         else
            break;
      }
      if (nb == n && n%2 == 0)
         cout << "Second" << '\n';
      else if (nb == n && n%2)
         cout << "First"<< '\n';
      else if (nb%2 == 0)
         cout << "First" << '\n';
      else
         cout << "Second" << '\n';
   }
}