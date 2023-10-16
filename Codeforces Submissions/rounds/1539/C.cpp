/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
			KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main()
{
   SaveTime
   int n; ll k,x; cin >> n >> k >> x;
   ll num[n];
   for (int i = 0; i < n; i++) {
      cin >> num[i];
   }
   int split = 1;
   sort(num, num+n);
   /// k = 0;
   vector<ll> v;
   for (int i = 1; i < n; i++) {
      if (num[i]-num[i-1] > x) {
         split++;
         ll nb = (num[i]-num[i-1])/x;
         if ((num[i]-num[i-1])%x == 0)
            nb--;
         v.push_back(nb);
      }
   }
   sort(v.begin(), v.end());
   for (int i = 0; i < v.size(); i++) {
      if (k >= v[i]) {
         split--;
         k-= v[i];
      }
   }
   cout << split;
}