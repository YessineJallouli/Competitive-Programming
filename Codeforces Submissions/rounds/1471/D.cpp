/*
    Failure is not the reason for you to stop trying
       it is actually a remainder that you should
            KEEP GOING
*/
#include<bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 1e6+7;
int p[mx];

int factorize(int n) {
   int N = n;
   int q = 1;
   for (int i = 2; i*i <= n; i++) {
      while (N%(i*i) == 0) {
         q = q*i*i;
         N = N/(i*i);
      }
   }
   return q;
}

int main()
{
   SaveTime
   int T; cin >> T;
   while (T--) {
      set<int> s;
      int n; cin >> n;
      int a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      int maxZero = 0;
      int maxOneCarre = 0;
      for (int i = 0; i < n; i++) {
         int q = factorize(a[i]);
         int v = a[i]/q;
         p[v]++;
         s.insert(v);
         maxZero = max(maxZero, p[v]);
         if (p[v] > 1 && p[v]%2 == 1 && v > 1) {
            maxOneCarre-= p[v]-1;
         }
         else if (p[v]%2 == 0 && v > 1) {
            maxOneCarre+= p[v];
         }
      }
      maxOneCarre+= p[1];
      int Q; cin >> Q;
      while (Q--) {
         ll w; cin >> w;
         if (w == 0)
            cout << maxZero << '\n';
         else {
            cout << max(maxZero, maxOneCarre) << '\n';
         }
      }
      for (int i : s)
         p[i] = 0;
   }
}