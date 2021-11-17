//https://codeforces.com/problemset/problem/52/C
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int N = 2e5+7;

ll tree[4*N], lazy[4*N], a[N];
bool marked[4*N];
int n;

ll mrg(ll a, ll b) {
   return min(a,b);
}

void build(int id = 0, int ns = 0, int ne = n-1) {
   if (ns == ne) {
      tree[id] = a[ns];
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   build(l, ns, md);
   build(r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

void unlazy(int id, int ns, int ne) {
   if (marked[id] == 0)
      return;
   tree[id]+= lazy[id];
   if (ns != ne) {
      int l = 2*id+1;
      int r = 2*id+2;
      int md = (ns+ne)/2;
      lazy[l]+= lazy[id];
      lazy[r]+= lazy[id];
      marked[l] = marked[r] = 1;
   }
   lazy[id] = 0;
   marked[id] = 0;
}

void upd(int qs, int qe, int v, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return;
   if (ns >= qs && ne <= qe) {
      marked[id] = 1;
      lazy[id]+= v;
      unlazy(id, ns, ne);
      return;
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   upd(qs, qe, v, l, ns, md);
   upd(qs, qe, v, r, md+1, ne);
   tree[id] = mrg(tree[l], tree[r]);
}

ll get(int qs, int qe, int id = 0, int ns = 0, int ne = n-1) {
   unlazy(id, ns, ne);
   if (ns > qe || ne < qs)
      return LLONG_MAX;
   if (ns >= qs && ne <= qe) {
      return tree[id];
   }
   int l = 2*id+1;
   int r = 2*id+2;
   int md = (ns+ne)/2;
   ll ln = get(qs, qe, l, ns, md);
   ll rn = get(qs, qe, r, md+1, ne);
   return mrg(ln, rn);
}

vector<int> v;

void extractIntegerWords(string &str)
{
    stringstream ss;
    ss << str;
    string temp;
    ll found;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found)
            v.push_back(found);
        temp = "";
    }
}

int main() {
   SaveTime
   cin >> n;
   for (int i = 0; i < n; i++)
      cin >> a[i];
   build();
   memset(lazy, 0, sizeof lazy);
   memset(marked, 0, sizeof marked);
   int q; cin >> q;
   cin.ignore();
   while (q--) {
      string s; getline(cin, s);
      v.clear();
      extractIntegerWords(s);
      if (v.size() == 2) {
         int a,b; a = v[0], b = v[1];
         if (a <= b) {
            cout << get(a,b) << '\n';
         }
         else {
            cout << min(get(a, n-1), get(0, b)) << '\n';
         }
      }
      else {
         int a,b,c; a = v[0], b = v[1], c = v[2];
         if (a <= b) {
            upd(a,b,c);
         }
         else {
            upd(a, n-1, c);
            upd(0, b, c);
         }
      }
   }
}
