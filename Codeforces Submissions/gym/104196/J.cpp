#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;

#define yes cout << "YES" << endl;
#define no  cout << "NO" << endl;
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
#define fastio ios_base::sync_with_stdio(false)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;

template <class Array_Type, class Tree_Type>
class segment_tree{
public:
	int size;
	vector<Tree_Type> tree;
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		tree.assign(size * 2, LONG_LONG_MAX);
	}
 
	void build(vector<Array_Type> &arr){
        init(arr.size());
		build(arr, 0, 0, size);
	}
 
 	void build(vector<Array_Type> &arr, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < arr.size()){
				tree[x] = arr[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(arr, 2*x+1, lx, m);
		build(arr, 2*x+2, m, rx);
		tree[x] = merge(x);
	}
 
	Tree_Type query(int l, int r){
		return query(l, r, 0, 0, size);
	}

 	Tree_Type query(int l, int r, int x, int lx, int rx){
		if(lx >= r || l >= rx) return LONG_LONG_MAX;
		if(lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		return min(query(l, r, 2*x+1, lx, m), query(l, r, 2*x+2, m, rx));
	}

	void update(int i, Array_Type v){
		update(i, v, 0, 0, size);
	}
 
	void update(int i, Array_Type v, int x, int lx, int rx){
		if(rx - lx == 1){
			tree[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if(i < m){
			update(i, v, 2*x+1, lx, m);
		}else{
			update(i, v, 2*x+2, m, rx);
		}
		tree[x] = merge(x);
	}

	Tree_Type merge(int x){
		Tree_Type left = tree[2*x+1];
		Tree_Type right = tree[2*x+2];
		return min(left, right);
	}
};


void solve(){
	ll n; cin >> n;
	vll arr(n);
	For(i, n) cin >> arr[i];
	segment_tree<ll, ll> st;
	st.build(arr);
	ll s = 1, e = n, r = st.tree[0] * n;
	For(i, n){
		ll left = i, right = i;
		ll l = 0, h = i;
		while(l <= h){
			ll mid = l + (h-l)/2;
			ll x = st.query(i-mid, i);
			if(x >= arr[i]){
				l = mid+1;
				left = i-mid;
			}else{
				h = mid-1;
			}
		}
		l = 0, h = n-i-1;
		while(l <= h){
			ll mid = l + (h-l)/2;
			ll x = st.query(i+1, i+mid+1);
			if(x >= arr[i]){
				l = mid+1;
				right = i+mid;
			}else{
				h = mid-1;
			}
		}
		ll res = arr[i] * (right - left + 1);
		if(res > r || (res == r && left+1 < s)){
			r = res;
			s = left+1;
			e = right+1;
		}
	}
	cout << s << " " << e << " " << r << endl;
}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int t = 1;
	// cin >> t;
	while(t--)
        solve();
	return 0;
}