#include<bits/stdc++.h>


using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      string A, B; cin >> A >> B;
      bool b = true;
      for (int i = 0; i < n; i++)
         if (A[i] > B[i])
            b = false;
      if (!b) {
         cout << -1 << '\n';
         continue;
      }
      int nb = 0;
      bool ch[26];
      for (int i = 0; i < 26; i++) {
         char minc = 'z';
         for (int j = 0; j < n; j++) {
            if (A[j] == i+'a' && A[j] != B[j])
               if (B[j] < minc)
                  minc = B[j];
         }
         if (minc != 'z') {
            bool b1 = false;
            for (int j = 0; j < n; j++) {
               char c = 'a'+i;
               if (A[j] == B[j] || A[j] != c)
                  continue;
               A[j] = minc;
               b1 = true;
            }
            if (b1)
               nb++;
         }
      }
      cout << nb << '\n';
   }
}