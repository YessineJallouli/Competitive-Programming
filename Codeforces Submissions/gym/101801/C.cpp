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


void solve(){
	int n, m, k; cin >> n >> m >> k;
	vvi grid(n, vi(m));
	For(i, n) 
		For(j, m) cin >> grid[i][j];
	vvi pref(n+1, vi(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = grid[i-1][j-1] + pref[i - 1][j] +
								pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	int lw = 0, rw = n;
	int ans = 0;
	auto check = [&](int midw, int midh){
		midw--, midh--;
		Forr(i, n+1, 1){
			if(i+midw > n) break;
			Forr(j, m+1, 1){
				if(j + midh > m) break;
				int x = pref[i+midw][j+midh] - pref[i-1][j+midh] 
						- pref[i+midw][j-1] + pref[i-1][j-1];
				if(x <= k) return 1;
			}
		}
		return 0;
	};
	Forr(midw, n+1, 1){
		int lh = 1, rh = m;
		while(lh <= rh){
			int midh = lh + (rh - lh) / 2;
			if(check(midw, midh)){
				ans = max(ans, midw * midh);
				lh = midh + 1;
			}else{
				rh = midh - 1;
			}
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