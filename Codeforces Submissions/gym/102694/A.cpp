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
int ans = 0;
int D = 0;
void longest_path(vector<int>&v, int prev, int prev2, int dist, int distmax)
{
   dist++;
   for (int i : v) {
      if (i != prev) {
         if (dist > D) {
            ans = i;
            distmax = dist;
            D = dist;
         }
         longest_path(tree[i], prev2, i, dist, distmax);
      }
   }
}

int main()
{
   int n; cin >> n;
   int k = 0;
   for (int i = 0; i < n-1; i++) {
      int a,b; cin >> a >> b;
      k = a;
      tree[a].push_back(b);
      tree[b].push_back(a);
   }
   longest_path(tree[1], -1, 1, 0, 0);
   D = 0;
   longest_path(tree[ans], -1, ans, 0,0);
   cout << D*3;
}