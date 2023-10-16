#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
   int n; cin >> n;
   ll ans = 1;
   int r = 1e9+7;
   for (int i = 2; i <= n; i++)
      ans = (ans*i)%r;
   int p2 = 1;
   for (int i = 0; i < n-1; i++)
      p2 = (p2*2)%r;
   ans = (ans-p2)%r;
   while (ans < 0)
      ans+= r;
   cout << ans;
}