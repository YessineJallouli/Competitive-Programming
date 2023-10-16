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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      sort(num, num+n);
      int N = INT_MAX;
      for (int i = 1; i < n; i++)
         N = min(num[i]-num[i-1], N);
      cout << N << '\n';
   }
}