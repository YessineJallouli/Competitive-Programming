//https://www.spoj.com/problems/ANDROUND/en/
#include <bits/stdc++.h>
using namespace std;

vector<long long> tree;

/// node = 1, left = 0, right = N-1, qA = a, qB = b

int mx = (1<<30)-1;

long long and_range(int node, int left, int right, int qA, int qB) {
   if (left >= qA && right <= qB)
      return tree[node];
   if (right < qA || left > qB)
      return mx;
   int mid = (left+right)/2;
   return (and_range(2*node, left, mid, qA, qB) & and_range(2*node+1, mid+1, right, qA, qB));
}

int main() {
   int T; cin >> T;
   while (T--) {
      int N,K; cin >> N >> K;
      K = min(K, N);
      int n = N;
      N*= 3;
      vector<int> a(N);
      for (int i = 0; i < N/3; i++)
         cin >> a[i];
      for (int i = 0; i < N/3; i++) {
         a[i+N/3] = a[i];
         a[i+2*N/3] = a[i];
      }
      while (N&(N-1)) {
         a.push_back(a[n-1]);
         N++;
      }
      tree.resize(2*N);
      for (int i = 0; i < N; i++) {
         tree[i+N] = a[i];
      }
      for (int i = N-1; i > 0; i--) {
         tree[i] = (tree[2*i] & tree[2*i+1]);
      }
      int save[n];
      for (int i = n; i < 2*n; i++) {
         save[i-n] = and_range(1,0,N-1, i-K, i+K);
      }
      for (int i = 0; i < n; i++)
         cout << save[i] <<  ' ';
      cout << '\n';
   }
}
