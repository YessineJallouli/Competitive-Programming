#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 4e6+7;

ll dp[mx];
int mod;

int nextElement(int thisElement, int n) {
   int lastElement = n/(thisElement+1);
   if (n/lastElement == thisElement)
      lastElement--;
   return n/lastElement;
}

int main() {
   memset(dp, -1, sizeof dp);
   int n; cin >> n >> mod;
   memset(dp, 0, sizeof dp);
   ll cum = 1;
   for (int i = n; i >= 1; i--) {
      dp[i] = (dp[i] + cum)%mod;
      int thisElement = 1;
      while (thisElement != i) {
         dp[thisElement] = (dp[thisElement] + (i/thisElement - i/(thisElement+1)) * dp[i])%mod;
         thisElement = nextElement(thisElement, i);
      }
      if (i != n)
         cum = (cum + dp[i])%mod;
   }
   cout << dp[1];
}