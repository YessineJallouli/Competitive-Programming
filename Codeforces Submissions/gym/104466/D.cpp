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

int a,b,c,d;
vector<ld> types;
ld dp[60][600];

ld work(int index,int sum){
	if(index==-1 && sum!=0) return 0.0;
	if(index==-1 && sum==0) return 1.0;
	if(sum<=0) return 0.0;
	if(dp[index][sum]!=-1.0) return dp[index][sum];
	int getyp=types[index];

	ld proba=0.0;
	for(int i=1;i<=getyp;i++){
		proba += ((1.0/(ld)getyp)) * work(index-1,sum-i);
	}
	return dp[index][sum]=proba;
}
void solve(){
	int f;
	cin >> a >> b >> c >> d >> f;

	for(int i=0;i<60;i++){
		for(int j=0;j<600;j++){
			dp[i][j]=-1.0;
		}
	}


	for(int i=0;i<a;i++){
		types.push_back(4);
	}

	for(int i=0;i<b;i++){
		types.push_back(6);
	}

		for(int i=0;i<c;i++){
		types.push_back(8);
	}

		for(int i=0;i<d;i++){
		types.push_back(12);
	}

	for(int i=0;i<f;i++){
		types.push_back(20);
	}

	for(int i=0;i<=500;i++){
		work(a+b+c+d+f-1,i);
	} 

	ld zero=0.0;

	vector<int> arr;
	for(int i=1;i<=500;i++){
		if(dp[a+b+c+d+f-1][i]>zero){
			arr.push_back(i);
		}
	}
	int l = 0, r = arr.size()-1;
	vector<int> ans;
	while(l < r){
		ans.push_back(arr[l++]);
		ans.push_back(arr[r--]);
	}
	if(l == r) ans.PB(arr[l]);
	reverse(all(ans));
	dd(ans);
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