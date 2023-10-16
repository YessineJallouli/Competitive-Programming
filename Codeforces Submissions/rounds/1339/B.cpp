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
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      sort(num, num+n);
      vector<int> v;
      if (n%2 == 1) {
         v.push_back(num[n/2]);
         int d = n/2-1;
         int f = n/2+1;
         for (int i = 0; i < n/2; i++) {
            v.push_back(num[d]);
            v.push_back(num[f]);
            d--; f++;
         }
      }
      else {
         int f = n/2;
         int d = n/2-1;
         for (int i = 0; i < n/2; i++) {
            v.push_back(num[d]);
            v.push_back(num[f]);
            d--; f++;
         }
      }
      for (int i : v)
         cout << i << ' ';
      cout << endl;
   }
}