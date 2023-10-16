#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int main()
{
   int n; cin >> n;
   int num[n];
   vector<int> nb;
   for(int i = 1; i < 100001; i++)
      nb.push_back(0);
   int nbfour = 0;
   int nbtwo = 0;
   int nbeight = 0;
   int nbsix = 0;
   for (int i = 0; i < n; i++) {
      cin >> num[i];
      nb[num[i]]++;
   }
   for (int i  = 1; i < 100001; i++) {
      if (nb[i] > 3)
         nbfour++;
      if (nb[i] > 1)
         nbtwo++;
      if (nb[i] > 7)
         nbeight++;
      if (nb[i] > 5)
         nbsix++;
   }
   int q; cin >> q;
   for (int i = 0; i < q; i++) {
      char s; cin >> s;
      int num; cin >> num;
      if (s == '+')
         nb[num]++;
      else
         nb[num]--;
      if (nb[num] == 3 && s == '-')
         nbfour--;
      if (nb[num] == 1 && s == '-')
         nbtwo--;
      if (nb[num] == 7 && s == '-')
         nbeight--;
      if (nb[num] == 5 && s == '-')
         nbsix--;
      if (nb[num] == 4 && s == '+')
         nbfour++;
      if (nb[num] == 2 && s == '+')
         nbtwo++;
      if (nb[num] == 8 && s == '+')
         nbeight++;
      if (nb[num] == 6 && s == '+')
         nbsix++;
      //cout << nbtwo << ' ' << nbfour << ' ' << nbsix << ' ' << nbeight << endl;
      if (nbeight > 0)
         cout << "YES" << '\n';
      else if (nbfour > 1)
         cout << "YES" << '\n';
      else if (nbsix > 0 && nbtwo > 1)
         cout << "YES" << '\n';
      else if (nbfour > 0 && nbtwo > 2)
         cout << "YES" << '\n';
      else
         cout << "NO" << '\n';
   }
}