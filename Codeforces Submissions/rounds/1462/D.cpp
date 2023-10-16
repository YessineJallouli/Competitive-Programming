#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      int num[n];
      for (int i = 0; i < n; i++) {
         cin >> num[i];
      }
      int x = 0;
      int mn = INT_MAX;
      int nbOp;
      for (int i = 0; i < n; i++) {
         x+= num[i];
         nbOp = i;
         int sum = 0;
         int nbBlock = 0;
         for (int j = i+1; j < n; j++) {
            sum+= num[j];
            nbBlock++;
            if (sum == x) {
               nbOp+= nbBlock-1;
               sum = 0;
               nbBlock = 0;
            }
            else if (sum > x) {
               nbOp = -1;
               break;
            }
         }
         if (nbOp != -1 && sum == 0) {
            mn = min(nbOp, mn);
         }
      }
      cout << mn << endl;
   }
}