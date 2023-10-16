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
      int pos[100000];
      for (int i = 0; i <= n; i++)
         pos[i] = -5;
      bool b = false;
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         if (pos[num[i]] != -5 && pos[num[i]] != i-1)
            b = true;
         else if (pos[num[i]] == -5)
            pos[num[i]] = i;
      }
      if (b) cout << "YES" << endl;
      else cout << "NO" << endl;
   }
}