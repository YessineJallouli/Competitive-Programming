#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int n; cin >> n;
   if (n < 4) {
      cout << "NO";
      return 0;
   }
   if (n%2 == 0) {
      cout << "YES" << endl;
      cout << "1 * 2 = 2" << endl << "2 * 3 = 6" << endl << "6 * 4 = 24" << endl;
      int nb = 0;
      for (int i = 6; i <= n; i+=2) {
         cout << i << " - " << i-1 << " = 1" << endl;
         nb++;
      }
      for (int i = 0; i < nb; i++)
         cout << "24 * 1 = 24" << endl;
   }
   else {
      cout << "YES" << endl;
      cout << "5 * 4 = 20" << endl << "20 + 3 = 23" << endl << "2 - 1 = 1" << endl << "23 + 1 = 24" << endl;
      int nb = 0;
      for (int i = 7; i <= n; i+=2) {
         cout << i << " - " << i-1 << " = 1" << endl;
         nb++;
      }
      for (int i = 0; i < nb; i++)
         cout << "24 * 1 = 24" << endl;
   }
}