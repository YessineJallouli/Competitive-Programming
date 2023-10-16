/*
	Failure is not the reason for you to stop trying
	   it is actually a reminder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

ll maxi(ll a, ll b) {
   if (a > b) return a;
   return b;
}

int main()
{
   ll n, k; cin >> n >> k;
   ll num[n];
   for (int i=0; i < n; i++) {
      cin >> num[i];
   }
   sort(num, num+n);
   ll nb = 1;
   ll x = 0;
   ll a = 0, b = 0;
   ll pr = -1;
   for (ll i = 1; i < n; i++) {
      b+= maxi(num[i] - num[0] -1, 0);
      if (num[i] == num[0]) {nb++; x = i;}
   }
   ll m = maxi(k-nb, 0);
   ll hM = b+m;
   if (nb >= k)
      hM = 0;
   for (ll i = x+1; i < n; i++) {
      if (num[i] != num[i-1]) {
          a+= ((num[i]-num[i-1]-1) * nb) + (i-nb)*(num[i]-num[i-1]);
          nb = 1;
          pr = num[i-1];
      }
      if (i+1 < n) {
         if (num[i] == num[i+1]) {
            nb++;
            continue;
         }
      }
      b-= (((num[i]-pr)* (n-i-1)) + ((num[i]-pr-1)*nb));
      ll g = i-nb +1;
      ll d = n-i-1;
      ll m = maxi(k-nb, 0);
      if (nb >= k)
         hM = 0;
      ll h;
      if (a > b) {
         if (d >= m)
            h = b+m;
         else if (g >= m)
            h = a+m;
         else
            h = a+b+m;
      }
      else if (a == b) {
         if (d >= m || g >= m)
            h = a+m;
         else
            h = a+b+m;
      }
      else {
         if (g >= m)
            h = a+m;
         else if (d >= m)
            h = b+m;
         else
            h = a+b+m;
      }
      if (hM > h) hM = h;
   }
   cout << hM;
}
