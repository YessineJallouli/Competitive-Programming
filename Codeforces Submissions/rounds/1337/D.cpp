#include<bits/stdc++.h>
#define MOD 1e9+7
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PI 4*atan(1)

using namespace std;

ll f(ll a, ll b, ll c) {
   return (a-b)*(a-b) + (a-c)*(a-c) + (b-c)*(b-c);
}

void Fill(int d, int id, vector<vector<int>> &V)
{
   for (int i = 0; i < d; i++) {
      int n; cin >> n;
      V[id].push_back(n);
   }
}

int B, B1, C, C1;
void Search(int X, vector<int> &v, int *p, int *p1)
{
   int Start = 0;
   int End = v.size()-1;
   while (End - Start > 1) {
      int mid = (Start + End)/2;
      if (v[mid] < X) Start = mid;
      else End = mid;
   }

   if (v[Start] == X || v[End] == X) {
      *p = *p1 = X;
      return;
   }
   *p = v[Start]; *p1 = v[End];
}

ll ansM = LLONG_MAX;
void getMin(int id, int L, vector<vector<int>> &V)
{
   for (int i = 0; i < L; i++) {
         int X = V[id][i];
         Search(X, V[(id+1)%3], &B, &B1);
         Search(X, V[(id+2)%3], &C, &C1);
         ll z = f(X, B, C);
         ll z1 = f(X, B, C1);
         ll z2 = f(X, B1, C);
         ll z3 = f(X, B1, C1);
         ansM = min({z, z1, z2, z3, ansM});
   }
}

int main()
{
   int T; cin >> T;
   while (T--) {
      ansM = LLONG_MAX;
      vector<vector<int>> V(3);
      int a, b, c; cin >> a >> b >> c;
      Fill(a,0, V); Fill(b,1, V); Fill(c,2, V);
      for (int i = 0; i < 3; i++)
         sort(V[i].begin(), V[i].end());
      getMin(0, a, V);
      getMin(1, b, V);
      getMin(2, c, V);
      cout << ansM << endl;
      V.clear();
   }
}