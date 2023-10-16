/*
    Failure is not a reason for you to stop trying
       it is actually a reminder that you should
            KEEP GOING
*/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

vector<int> tree;

int gcd_range(int node, int left, int right, int qA, int qB) {
   if (left >= qA && right <= qB)
      return tree[node];
   if (right < qA || left > qB)
      return 0;
   int mid = (left+right)/2;
   return __gcd(gcd_range(2*node, left, mid, qA, qB) , gcd_range(2*node+1, mid+1, right, qA, qB));
}

bool can_obtain(int len, int gcd, int N, int n) {
   for (int i = 0; i < n; i++) {
      if (i+len-1 < n) {
         int gcd1 = gcd_range(1, 0, N-1, i, i+len-1);
         if (gcd1 != gcd)
            return false;
      }
      else {
         int gcd1 = gcd_range(1, 0, N-1, i, n-1);
         int part2 = len-n+i-1;
         int gcd2 = gcd_range(1, 0, N-1, 0, part2);
         if (__gcd(gcd1, gcd2) != gcd)
            return false;
      }
   }
   return true;
}

int main() {
   SaveTime
   int T; cin >> T;
   while (T--) {
      int N; cin >> N;
      vector<int> a(N);
      for (int i = 0; i < N; i++)
         cin >> a[i];
      int ans = a[0];
      int n = N-1;
      for (int i = 0; i < N; i++)
         ans = __gcd(ans, a[i]);
      while (N&(N-1)) {
         a.push_back(a[n]);
         N++;
      }
      tree.resize(2*N);
      for (int i = 0; i < N; i++) {
         tree[i+N] = a[i];
      }
      for (int i = N-1; i > 0; i--) {
         tree[i] = __gcd(tree[2*i],tree[2*i+1]);
      }
      int Left = 0, Right = n+1, res = n+1;
      while (Left <= Right) {
         int middle = (Left+Right)/2;
         if (! can_obtain(middle, ans, N, n+1)) {
            Left = middle+1;
         }
         else {
            res = middle;
            Right = middle-1;
         }
      }
      cout << res-1 << '\n';
   }
}