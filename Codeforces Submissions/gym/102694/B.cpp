#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;
const int mx = 300007;
vector<vector<int>> tree(mx);
map<int, bool> m;
int h = 0;
int ans = 1;
int D = 0;
void longest_path(vector<int>&v, int prev, int prev2, int dist, int distmax)
{
   dist++;
   for (int i : v) {
      if (i != prev) {
         if (dist >= D) {
            ans = i;
            distmax = dist;
            D = dist;
         }
         if (dist == h) {
            m[i] = true;
         }
         longest_path(tree[i], prev2, i, dist, distmax);
      }
   }
}

int main()
{
   SaveTime
   int n; cin >> n;
   int k = 0;
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   longest_path(tree[1], -1, 1, 0, 0);
   D = 0;
   longest_path(tree[ans], -1, ans, 0,0);
   h = D; D = 0;
   m[ans] = true;
   longest_path(tree[ans], -1, ans, 0,0);
   longest_path(tree[ans], -1, ans, 0,0);
   for (int i = 1; i <= n; i++) {
      if (m[i])
         cout << D+1 << '\n';
      else
         cout << D << '\n';
   }
}