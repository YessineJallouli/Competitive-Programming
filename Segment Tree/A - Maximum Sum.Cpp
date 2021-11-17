//https://www.spoj.com/problems/KGSS/en/
#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, int>> tree;

/// node = 1, left = 0, right = N-1, qA = a, qB = b

pair<long long, int> max_range(int node, int left, int right, int qA, int qB) {
   if (left >= qA && right <= qB)
      return tree[node];
   if (right < qA || left > qB)
      return {0,-1};
   int mid = (left+right)/2;
   return max(max_range(2*node, left, mid, qA, qB) , max_range(2*node+1, mid+1, right, qA, qB));
}


void update(int id, int v, int n) {
   tree[n+id] = {v, id};
   for (int i = (n+id)/2; i > 0; i/= 2) {
      tree[i] = max(tree[2*i], tree[2*i+1]);
   }
}

int main() {
   int N; cin >> N;
   vector<int> a(N);
   for (int i = 0; i < N; i++)
      cin >> a[i];
   while (N&(N-1)) {
      a.push_back(0);
      N++;
   }
   tree.resize(2*N);
   for (int i = 0; i < N; i++) {
      tree[i+N] = {a[i],i};
   }
   for (int i = N-1; i > 0; i--) {
      tree[i] = max(tree[2*i] , tree[2*i+1]);
   }
   int Q; cin >> Q;
   while (Q--) {
      char c; int a,b; cin >> c >> a >> b;
      if (c == 'U') {
         update(a-1,b,N);
      }
      else {
         a--; b--;
         pair<long long,int> p = max_range(1,0, N-1,a,b);
         int mx1 = p.first;
         int id = p.second;
         int mx2 = max(max_range(1,0, N-1, a,id-1).first, max_range(1,0,N-1, id+1, b).first);
         cout << mx1+mx2 << '\n';
      }
   }
}
