#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> p;
      vector<int> n;
      for (int i = 0; i < N; i++) {
         int a; cin >> a;
         if (a > 0)
            p.push_back(a);
         else
            n.push_back(a);
      }
      sort(p.rbegin(), p.rend());
      sort(n.begin(), n.end());
      ll ANS = LONG_LONG_MIN;
      int a = p.size();
      int b = n.size();
      for (int nbP = 0; nbP <= 5; nbP++) {
         ll ans = 1;
         int nbN = 5-nbP;
         if (nbP > a || nbN > b)
            continue;
         if (nbN%2 == 1)
            for (int i = b-1; i >= b-nbN; i--)
               ans*= n[i];
         else
            for (int i = 0; i < nbN; i++)
               ans*= n[i];
         if (nbN%2 == 1)
            for (int i = a-1; i >= a-nbP; i--)
               ans*= p[i];
         else
            for (int i = 0; i < nbP; i++)
               ans*= p[i];
         ANS = max(ans, ANS);
      }
      cout << ANS << endl;
   }
}