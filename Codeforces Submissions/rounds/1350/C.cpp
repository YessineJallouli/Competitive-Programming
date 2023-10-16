#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int num[200001];

ull pcm(ull a, ull b)
{
   return (a*b)/__gcd(a,b);
}

int main()
{
   int n; cin >> n;
   int num[n];
   for (int i = 0; i < n; i++) {
      cin >> num[i];
   }

   int suffix_gcd[n];
   int prefix_gcd[n];
   prefix_gcd[0] = num[0];
   suffix_gcd[n-1] = num[n-1];
   for (int i = 1; i < n; i++) {
      prefix_gcd[i] = __gcd(num[i], prefix_gcd[i-1]);
   }
   for (int i = n-2; i>= 0; i--) {
      suffix_gcd[i] = __gcd(num[i], suffix_gcd[i+1]);
   }
   ull ans = 1;
   for (int i = 0; i < n; i++) {
      ull N;
      if (i == 0)
         N = suffix_gcd[i+1];
      else if (i == n-1)
         N = prefix_gcd[i-1];
      else
         N = __gcd(prefix_gcd[i-1], suffix_gcd[i+1]);
      ans = pcm(N, ans);
   }
   cout << ans;
}