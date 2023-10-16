#include <bits/stdc++.h>
using namespace std;

int f(int x) {
   return x*x;
}

const int N = 1007;

vector<vector<int>> graph(N);

bool visite[N];
double p[N];

double dp[N];

double dfs(int node) {
   if (visite[node])
      return dp[node];
   visite[node] = true;
   double ans = p[node];
   for (int ch : graph[node]) {
      ans = max(ans, p[node] + dfs(ch));
   }
   return dp[node] = ans;
}

int main()
{
   int n; cin>>n;
   vector<tuple<int,int,int,float>> v;
   for (int i = 0; i < n ; i++) {
      int a,b,c; float d;
      cin >> a >> b >> c >> d;
      v.push_back({c,a,b,d});
  }
   sort(v.begin(), v.end());
   int x[n], y[n], t[n];
   for (int i = 0; i < n; i++) {
      x[i] = get<1>(v[i]); y[i] = get<2>(v[i]); t[i] = get<0>(v[i]); p[i] = get<3>(v[i]);
   }
   for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
         if (sqrt(f(x[j]-x[i]) + f(y[j]-y[i])) <= (t[j]-t[i])) {
             graph[i].push_back(j);
         }
      }
   }
   double ans = 0;
   memset(visite, false, sizeof visite);
   memset(dp, -1, sizeof dp);
   for (int i = 0; i < n; i++) {
      ans = max(ans , dfs(i));
   }
   cout.precision(20);
   cout << ans;
}