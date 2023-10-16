#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

bool isprime(int n)
{
   if (n < 4)
      return true;
   if (n%2 == 0 || n%3 == 0)
      return false;
   for (int i = 3; i*i <= n; i+= 2)
      if (n%i == 0)
         return false;
   return true;
}

int main()
{
   int T; cin >> T;
   while (T--)
   {
      int n1, k;
      cin >> n1 >> k;
      ull ans;
      if (isprime(n1))
         ans = 2*n1 + 2*(k-1);
      else if (n1 % 2 == 0)
         ans = n1 + k*2;
      else
      {
         for (int i = 2; i*i <= n1; i++)
            if (n1 % i == 0) {
               ans = n1+i;
               break;
            }
         ans+= (k-1)*2;
      }
      cout << ans << '\n';
   }
}