#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

int main() {
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      n*= 2;
      int num[n];
      for (int i = 0; i < n; i++)
         cin >> num[i];
      for (int i = 0; i < 1000; i++) {
         bool b = true;
         random_shuffle(num, num+n);
         for (int j = 0; j < n; j++) {
            int p = j-1;
            if (p < 0)
               p+= n;
            if (num[j] == (num[(j+1)%n]+num[p])/2)
               b = false;
         }
         if (b)
            break;
      }
      for (int i = 0; i < n; i++)
         cout << num[i] << ' ';
      cout << endl;
   }
}