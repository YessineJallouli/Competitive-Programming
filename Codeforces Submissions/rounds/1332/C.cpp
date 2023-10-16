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
      int n, k; cin >> n >> k;
      string s[(int)(n/k)];
      string h; cin >> h;
      for (int i = 0; i < n/k; i++)
         s[i] = h.substr(i*k, k);

      int occ[26] = {0};
      int nb = 0;
      for (int i = 0; i < s[0].size()/2; i++)
      {
          int l = s[0].size();
          for (int j = 0; j < n/k; j++) {
             occ[s[j][i] - 'a']++;
             occ[s[j][l-i-1] - 'a']++;
          }
          int maxi = 0;
          for (int j = 0; j < 26; j++) {
             if (occ[j] > maxi) maxi = occ[j];
             occ[j] = 0;
          }
          nb+= 2*(n/k) - maxi;
      }
      if (s[0].size() % 2 == 1)
      {
         int l = s[0].size() / 2;
         for (int j = 0; j < n/k; j++)
             occ[s[j][l] - 'a']++;
         int maxi = 0;
         for (int j = 0; j < 26; j++) {
            if (occ[j] > maxi) maxi = occ[j];
             occ[j] = 0;
         }
         nb+= (n/k) - maxi;
      }
      cout << nb << endl;
   }
}