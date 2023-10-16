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
map<int,int> mp;
const int NAX=2e5+5;
vector<int> colors(NAX);
vector<int> adj[NAX];
vector<int> colorcount(NAX);
bool t=false;


int sz[NAX];
int parr[NAX];
int nodeboum=0;
void dfs(int node,int par){
	if(nodeboum!=0) return;
	parr[node]=par;
	sz[node]=1;
	for(auto el:adj[node]){
		if(par==el) continue;
		dfs(el,node);
		sz[node]+=sz[el];
	}

	if(sz[node]==n/2){
		nodeboum=node;
		return;
	}

}


void dfs2(int node,int par){

	mp[colors[node]]++;

	for(auto el:adj[node]){
		if(par==el) continue;
		dfs2(el,node);
	}

}
void solve(){
	cin >> n;	
	nodeboum=0;
	mp.clear();
	for(int i=0;i<=n;i++){
		colorcount[i]=0;
		parr[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin >> colors[i];
		colorcount[colors[i]]++;
	}
	for(int i=0;i<=n;i++){
		adj[i].clear();
	}

	for(int i=0;i<n-1;i++){
		int from,to;
		cin >> from >> to;

		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for(int i=0;i<=n;i++){
		debug() << imie(i) imie(colorcount[i]);
		if(colorcount[i]%2==1){
		
			cout << -1 << "\n";
			//debug() << imie(i);
			return;
		}
	}
	dfs(1,0);
	debug() << imie(nodeboum);
	dfs2(nodeboum,parr[nodeboum]);

	ll counter=0;
	debug() << imie(mp);
	for(int i=1;i<=n;i++){ 
		if(mp[i]>colorcount[i]/2){
			counter+=(mp[i]-colorcount[i]/2);
		}

	}
	if(nodeboum==0){
		cout << -1 << "\n";
		return;
	}
	cout << counter << "\n";


	




	
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
	cin >> tc;
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