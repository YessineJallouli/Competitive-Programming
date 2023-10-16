#include <bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long

using namespace std;

const int sMax = 100001;
const int idM = 101;
int dp[idM][sMax];
int num[idM];
int n;

int fnd(int id, int sum) {
   if (dp[id][sum] != -1)
      return dp[id][sum];
   if (id == n)
      return dp[id][sum] = false;
   if (sum < 0)
      return dp[id][sum] = false;
   if (sum == 0)
      return dp[id][sum] = true;
   return dp[id][sum] = (fnd(id+1, sum-num[id]) | fnd(id+1, sum));
}


int main()
{
   memset(dp, -1, sizeof dp);
   cin >> n;
   int sum = 0;
   for (int i = 0; i < n; i++) {
      cin >> num[i];
      sum+= num[i];
   }
   if (sum%2 == 1) {
      cout << 0;
      return 0;
   }
   if (!fnd(0, sum/2)) {
      cout << 0;
      return 0;
   }
   while (true) {
      for (int i = 0; i < n; i++) {
         if (num[i]%2 == 1) {
            cout << 1 << endl << i+1;
            return 0;
         }
      }
      for (int i = 0; i < n; i++) {
         num[i] = num[i]/2;
      }
   }
}