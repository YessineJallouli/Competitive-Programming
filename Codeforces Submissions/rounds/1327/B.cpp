/*
	Failure is not the reason for you to stop trying
	   it is actually a remainder that you should
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

int main()
{
   int T; cin >> T;
   while (T--) {
      int nb; cin >> nb;
      unordered_map<int, bool> v;
      unordered_map<int, int> mari;
      for (int i = 0; i < nb; i++) {
         int n; cin >> n;
         bool b = false;
         for (int t = 0; t < n; t++) {
            int num; cin >> num;
            if (!v[num] && ! b)  {
               b = true;
               v[num] = true;
               mari[i] = num;
            }
         }
      }
      int a = -1, b = -1;
      for (int i = 0; i < nb; i++) {
         if (mari[i] == 0)
         {
            a = i+1;
            for (int k = 1; k <= nb; k++) {
               if (! v[k]) {
                  b = k;
                  break;
               }
            }
            if (b != -1)
               break;
         }
      }
      if (a != -1 && b != -1)
         cout << "IMPROVE\n" << a << ' ' << b << endl;
      else
         cout << "OPTIMAL" << endl;
   }
}