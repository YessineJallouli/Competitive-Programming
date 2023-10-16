#include <bits/stdc++.h>
#define ll long long
using namespace std;

int len(int n) {
   if (n == 0)
      return 0;
   return 1+len(n/10);
}

int main()
{
      int n; cin >> n;
      int q; cin  >> q;
      int num[n];
      int id[51];
      for (int i = 1; i < 51; i++) {
         id[i] = n;
      }
      for (int i = 0; i < n; i++) {
         cin >> num[i];
         if (i < id[num[i]])
            id[num[i]] = i+1;
      }
      for (int i = 0; i < q; i++) {
         int c; cin >> c;
         cout << id[c] << ' ';
         for (int j = 1; j < 51; j++) {
            if (id[j] == n)
               continue;
            if (id[j] < id[c])
               id[j]++;
         }
         id[c] = 1;
      }
}