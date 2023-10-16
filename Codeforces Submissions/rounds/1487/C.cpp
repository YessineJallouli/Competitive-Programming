#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      if (n == 2) {
         cout << 0 << endl;
         continue;
      }
      if (n%2 == 1) {
         int dp[n][n];
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               dp[i][j] = -2;
            }
         }
         int nbwin[n];
         int nbloose[n];
         memset(nbwin, 0, sizeof nbwin);
         memset(nbloose, 0, sizeof nbloose);
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (i != j) {
                  if (nbwin[i] < n/2 && nbloose[j] < n/2 && dp[j][i] == -2) {
                     nbwin[i]++;
                     nbloose[j]++;
                     dp[i][j] = 1;
                  }
               }
            }
         }
         for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
               if (dp[i][j] == -2 && dp[j][i] == -2)
                  cout << 0 << ' ';
               else if (dp[i][j] == 1)
                  cout << 1 << ' ';
               else
                  cout << -1 << ' ';
            }
         }
         cout << endl;
         continue;
      }
         int dp[n][n];
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               dp[i][j] = -2;
            }
         }
         for (int i = 0; i < n; i+= 2) {
            dp[i][i+1] = 0;
         }
         int nbwin[n];
         int nbloose[n];
         memset(nbwin, 0, sizeof nbwin);
         memset(nbloose, 0, sizeof nbloose);
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (i != j && dp[i][j] == -2) {
                  if (nbwin[i] < (n-1)/2 && nbloose[j] < (n-1)/2 && dp[j][i] == -2) {
                     nbwin[i]++;
                     nbloose[j]++;
                     dp[i][j] = 1;
                  }
               }
            }
         }
         for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
               if (dp[i][j] == 0)
                  cout << 0 << ' ';
               else if (dp[i][j] == 1)
                  cout << 1 << ' ';
               else
                  cout << -1 << ' ';
            }
         }
         cout << endl;
         continue;
   }
}