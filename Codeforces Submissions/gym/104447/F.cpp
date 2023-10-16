#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define endl '\n';
#define yes cout << "YES\n";
#define no  cout << "NO\n";
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

struct node{
	ll ans, pref, suff, somme;
	node(ll ans,ll pref, ll suff, ll somme)
		: ans(ans), pref(pref), suff(suff), somme(somme){};
};
 
struct segment_tree{
	int size; 
	vector<node> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(2*size, node(0, 0, 0, 0));
	}
 
	void build(vll &arr){
		init(arr.size());
		build(arr, 0, 0, size);
	}
 
	void build(vll &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				ll v = max(arr[lx], 0LL);
				tree[x] = node(v, v, v, arr[lx]);
			}
			return;
		}
		int m = (lx+rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = merge(x);
	}
	void update(int i, int v){
		update(i, v, 0, 0, size);
	}
	void update(int i, ll v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = node(max(v, 0LL), max(v, 0LL), max(v, 0LL), v);
			return;
		}
		int m = (lx+rx) / 2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		tree[x] = merge(x);
	}
	node query(int l, int r){
		return query(l, r, 0, 0, size);
	}

 	node query(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return node(0, 0, 0, 0);
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		node left = query(l, r, 2*x+1, lx, m);
		node right = query(l, r, 2*x+2, m, rx);
		ll pref = max(left.pref, left.somme+right.pref);
		ll suff = max(right.suff, left.suff + right.somme);
		ll ans = max(left.ans, max(right.ans, left.suff + right.pref));
		return node(ans, pref, suff, left.somme+right.somme);
	}
 
	node merge(int x){
		node left = tree[2*x+1];
		node right = tree[2*x+2];
		ll pref = max(left.pref, left.somme+right.pref);
		ll suff = max(right.suff, left.suff + right.somme);
		ll ans = max(left.ans, max(right.ans, left.suff + right.pref));
		return node(ans, pref, suff, left.somme+right.somme);
	}
};

void solve(){
	ll n, k; cin >> n >> k;
	vstr arr(n);
	vll operations(n);
	For(i, n){
		cin >> arr[i];
		int l = 0, r = arr[i].size() - 1;
		while(l < r){
			operations[i] += (arr[i][l] != arr[i][r]);
			l++, r--;
		}
	}
	vll scores(n);
	For(i, n){
		cin >> scores[i];
	}
	segment_tree st;
	st.build(scores);
	int l = -1;
	ll tot = 0;
	ll ans = 0;
	For(i, n){
		while(l != -1 && l < i && tot + operations[i] > k){
			tot -= operations[l];
			l++;
		}
		if(tot + operations[i] > k){
			l = -1;
		}else{
			if(l == -1) l = i;
			tot += operations[i];
			ans = max(ans, st.query(l, i+1).ans);
		}
	}
	cout << ans << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
	return 0;
}