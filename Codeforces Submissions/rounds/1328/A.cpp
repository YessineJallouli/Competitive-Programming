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
      ull a, b;
      cin >> a >> b;
      ull k = floor(a/b);
      cout << (b-(a - k*b)) % b << endl;
   }
}