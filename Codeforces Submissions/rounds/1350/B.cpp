#include<bits/stdc++.h>
#define SaveTime ios_base::sync_with_stdio(false);cin.tie(0);
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

int ans = 0;
void GG(int &n, vector<int> &v, int nb, int id, map<int,bool>&m)
{
   m[id-1] = true;
   ans = max(ans, nb);
   //cout << nb << endl;
   for (int i = 2*id; i <= n; i+= id) {
      int N = v[i-1];
      if (N > v[id-1])
         GG(n, v, nb+1, i, m);
   }
}

int main()
{
   int T; cin >> T;
   while (T--) {
      int n; cin >> n;
      vector<int> num;
      map<int,bool> visited;
      for (int i = 0; i < n; i++) {
         int K; cin >> K;
         num.push_back(K);
      }
      for (int i = 0; i < n; i++) {
         if (visited[i])
           continue;
         GG(n,num,1, i+1, visited);
      }
      cout << ans << '\n';
      ans = 0;
      num.clear();
      visited.clear();
   }
}