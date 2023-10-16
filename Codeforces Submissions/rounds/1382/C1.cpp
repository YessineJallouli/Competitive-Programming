#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

void rev(int id, string &s) {
   for (int i = 0; i <= id; i++) {
      if (s[i] == '0')
         s[i] = '1';
      else
         s[i] = '0';
   }
   reverse(s.begin(), s.begin() + id+1);
}

int main()
{
   SaveTime
   int t; cin >> t;
   while (t--) {
      int n; cin >> n;
      string a,b;
      cin >> a >> b;
      int k = 0;
      vector<int> v;
      for (int i = n-1; i >= 0; i--) {
         if (a[i] == b[i])
            continue;
         if (a[0] != a[i]) {
            v.push_back(1);
            k+=2;
            a[0] = a[i];
            rev(i, a);
         }
         else {
            k++;
            rev(i,a);
         }
         v.push_back(i+1);
      }
      cout << k << ' ';
      for (int i : v)
         cout << i << ' ';
      cout << '\n';
      v.clear();
   }
}