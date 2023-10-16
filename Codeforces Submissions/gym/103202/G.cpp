/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

int main() {
   SaveTime
   int n,k; cin >> n >> k;
   int num[n];
   for (int i=  0; i <n; i++)
      cin >> num[i];
   sort(num, num+n);
   ll ans = 0;
   for (int i = n-1; i > n-1-k; i--) {
      ans+= num[i];
   }
   cout << ans;
}