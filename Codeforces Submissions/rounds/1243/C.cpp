#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

bool prime(ll n)
{
   if (n% 2 == 0)
      return false;
   for (int i = 3; i <= sqrt(n); i+=2)
      if (n% i == 0)
         return false;
   return true;
}

ll nbFactor (ll n) {
   if (prime(n))
      return n;
   ll h = n;
   bool b = false;
   for (int i = 2; i <= sqrt(n+2); i++)
   {
      while (h%i == 0)
      {
         b = true;
         h/= i;
      }
      if (b) {
         if (h == 1)
            return i;
         return 1;
      }
   }
}

int main()
{
   ll n; cin >> n;
   cout << nbFactor(n);
}