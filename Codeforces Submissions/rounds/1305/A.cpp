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
   while (T--)  {
      int n; cin >> n;
      int a[n], b[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      for (int i = 0; i < n; i++)
         cin >> b[i];
      sort(a, a+n); sort(b, b+n);
      for (int i = 0; i < n; i++)
         cout << a[i] << ' ';
      cout << endl;
      for (int i = 0; i < n; i++)
         cout << b[i] << ' ';
      cout << endl;
   }
}