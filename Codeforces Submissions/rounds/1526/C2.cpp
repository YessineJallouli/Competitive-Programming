#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace  std;

const int mx = 2e5+7;
vector<int> v;
ll dp[mx];

int main() {
   SaveTime
   int n; cin >> n;
   int num[n];
   ll sum = 0;
   int ans = 0;
   priority_queue<int> q;
   int nb = 0;
   for (int i = 0; i < n; i++) {
      cin >> num[i];
      sum+= num[i];
      if (num[i] < 0)
         q.push(-1*num[i]);
      while (sum < 0) {
         sum+= q.top();
         q.pop();
         nb++;
      }
   }
   cout << n-nb;
}