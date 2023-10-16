#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

string tobinary(ll n)
{
   string s = "";
   for (int i = 63; i >= 0; i--) {
      int k = n >> i;
      if (k & 1)
         s+= '1';
      else
         s+= '0';
   }
   return s;
}

int main()
{

   int n; cin >> n;
   vector<pair<string,ll>> v;
   for (int i = 0; i < n; i++)
   {
      ll num; cin >> num;
      v.push_back({tobinary(num), num});
   }
   ll ansM = 0;
   ll a,b,c;
   for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
         for (int k = j+1; k < n; k++) {
            ll ans = v[i].second;
            ans |= v[j].second;
            ans |= v[k].second;
            if (ansM < ans) {
               a = v[i].second;
               b = v[j].second;
               c = v[k].second;
               ansM = ans;
            }
         }
      }
   }
   if (n <= 3)
   {
      ll ans = 1;
      for (int i = 0; i < n; i++)
         ans|= v[i].second ;
      cout << ans;
      return 0;
   }
   sort(v.rbegin(), v.rend());
   string s = v[0].first;
   ll n1 = v[0].second;
   for (int i = 1; i < n; i++) {
      string inf = v[i].first;
      for (int j = 0; j < 64; j++) {
         if (s[j] == inf[j] && s[j] == '1') {
            inf[j] = '0';
         }
      }
      ll hh = v[i].second;
      v[i]= {inf, hh};
   }
   v.erase(v.begin());
   sort(v.rbegin(), v.rend());
   ll n2 = v[0].second;
   s = v[0].first;
   for (int i = 1; i < n-1; i++) {
      string inf = v[i].first;
      for (int j = 0; j < 64; j++) {
         if (s[j] == inf[j] && s[j] == '1') {
            inf[j] = '0';
         }
      }
      ll hh = v[i].second;
      v[i] = {inf, hh};
   }
   v.erase(v.begin());
   sort(v.rbegin(), v.rend());
   ll n3 = v[0].second;
   ll ans = n1;
   ans|= n2;
   ans|= n3;
   cout << ansM;
}