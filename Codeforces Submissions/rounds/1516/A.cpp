#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n,k; cin >> n >> k;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int id = 0;
      for (int i = 0; i < k; i++) {
         while (num[id] == 0 && id != n-1)
            id++;
         if (id == n-1)
             break;
         if (num[id] > 0) {
            num[id]--;
         }
         if (num[id] == 0)
            id++;
         num[n-1]++;
      }
      for (int i = 0; i < n; i++)
         cout << num[i] << ' ';
      cout << endl;
   }
}