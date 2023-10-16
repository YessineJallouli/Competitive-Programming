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
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      ll DiffMaxi = 0;
      ll Diff;
      ll curr = num[0];
      for (int i = 0; i < n; i++) {
         if (num[i] > curr)
            curr = num[i];
         Diff = curr - num[i];
         if (DiffMaxi < Diff)
            DiffMaxi = Diff;
      }
      int nb;
      if (abs(ceil(log2(DiffMaxi)) - log2(DiffMaxi)) < 0.00001)
         nb = ceil(log2(DiffMaxi)) +1;
      else
         nb = ceil(log2(DiffMaxi));
      cout << max(0,nb) << endl;
   }
}