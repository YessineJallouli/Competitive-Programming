// WE ARE NOT HERE TO TAKE PART , WE ARE HERE TO TAKE OVER
#include <bits/stdc++.h>
using namespace std;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
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
#define         aff(v) for(auto e:v) cout<<e<<" ";cout<<endl;
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define yes(check) cout << (check ? "YES" : "NO") << endl
typedef long long ll;
typedef long double ld;
ll n,q,d;
const ll prime=1e9+7;
const ll prime2=998244353;
const ll prime3=7901;

const ll MOD = 998244353;
ll INF=2e18;

void solve(){
	cin >> n;
	vector<ll> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}

	sort(vec.begin(),vec.end());
	vector<ll> suff(n);
	for(int i=n-1;i>=0;i--){
		suff[i]=(i<n-1?suff[i+1]:0)+vec[i];
	}
	ll k;
	cin >> k;
	vector<pair<ll,ll>> queries;
	for(int i=0;i<k;i++){
		ll l;
		cin >>l;
		queries.push_back({l,i});
	}

	sort(queries.begin(),queries.end());
	vector<ll> ans(k);
	ll curreind=0;
	debug() << imie(suff);
	for(ll i=0;i<n;i++){
		ll currentleng=vec[i];
		debug() << imie(vec[i]);
		while(curreind<(int)queries.size() && currentleng>=queries[curreind].first){
			debug() << imie(suff[i]);
			ans[queries[curreind].second]=suff[i]-queries[curreind].first*(n-(i));
			debug() << imie(n-(i+1));
			curreind++;
		}
	}

	for(int i=0;i<k;i++){
		cout << ans[i]<<'\n';
	}
	
}
	
	

 
int main() {
	fastInp;
	//init();
	//debug() << imie(s);
	//freopen("grids.in","r",stdin);
	//freopen("res.out","w",stdout);
	// __gcd <long long> (x, y);
	int tc=1;
	//debug() << imie(sieve);
	//cin >> tc;
	//cout << setprecision(10)<<fixed;

	while(tc--){
		//i++;
		//cout <<"Test " << i << ":" << "\n";
		
		solve();
		
	}

	return 0;
}

/*
   Some insights:
    .Binary search
    .Graph representation
    .Write brute force code
    .Change your approach
 
 
 */