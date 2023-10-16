#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main ()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n+1];
      int nb[n+1];
      memset(nb, 0, sizeof nb);
      ll sum = 0;
      for (int i = 0; i < n; i++) {
         cin >> num[i+1];
         sum+= num[i+1];
      }
      deque<pair<int,int>> p(n);
      for (int i = 1; i<= n; i++) {
         p[i-1].first = num[i];
         p[i-1].second = i;
      }
      sort(p.rbegin(), p.rend());
      for (int i = 0; i < n-1; i++) {
         int a, b; cin >> a >> b;
         nb[a]++;
         nb[b]++;
      }
      for (int i = 0; i < n-1; i++) {
         cout << sum << ' ';
         if (p.size() != 0) {
            while (nb[p[0].second] == 1) {
               p.pop_front();
               if (p.size() == 0) {
                  break;
               }
            }
         }
         if (p.size() == 0) {
            break;
         }
         sum+= p[0].first;
         nb[p[0].second]--;
      }
      cout << endl;
      p.clear();
   }
}