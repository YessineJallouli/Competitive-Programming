#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a,b,c;
const int M = 201;

ll dp[M][M][M];
ll A[M], B[M], C[M];
ll solve(int i, int j, int k) {
   int nb = (i < a) + (j < b) + (k < c);
   if (nb < 2)
      return 0;
   ll ans = dp[i][j][k];
   if (ans != -1)
      return ans;
   ans = 0;
   if (i < a && j < b)
      ans = max(ans, A[i] * B[j] + solve(i+1, j+1, k));
   if (i < a && k < c)
      ans = max(ans, A[i] * C[k] + solve(i+1, j, k+1));
   if (j < b && k < c)
      ans = max(ans, B[j] * C[k] + solve(i, j+1, k+1));
   return dp[i][j][k] = ans;
}


int main()
{
   cin >> a >> b >> c;
   for (int i = 0; i < a; i++) {
      cin >> A[i];
   }
   for (int i = 0; i < b; i++) {
      cin >> B[i];
   }
   for (int i = 0; i < c; i++) {
      cin >> C[i];
   }
   sort(A, A+a);
   reverse(A, A+a);
   sort(B, B+b);
   reverse(B, B+b);
   sort(C, C+c);
   reverse(C, C+c);
   memset(dp, -1, sizeof dp);
   cout << solve(0,0,0);
}