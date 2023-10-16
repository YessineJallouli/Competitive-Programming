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
const int NAX=1e3+5;
int depth[NAX];
map<ll,ll> res;
map<ll,bool> nodes;
vector<ll> adj[NAX];
ll maxi=0;
ll k;
int dfs(int node,int p=0){

	depth[node]=depth[p]+1;
	bool anotherone=false;
	ll sum=0;
	ll cntr=0;
	if(nodes[node]){
		anotherone=true;	
		cntr++;
		sum+=1;
	}

	for(auto el:adj[node]){
		if(el==p) continue;
		ll giveme=dfs(el,node);
		if(giveme){
			sum+=giveme;
			cntr++;
		}
	}

	if((cntr>=2 || anotherone)&&sum>=k ){
		res[depth[node]]++;
		maxi=max(maxi,(ll)depth[node]);
	}

	return sum;

}
void solve(){
	cin >> n>>q;
	for(int i=0;i<=n;i++){
		adj[i].clear();
		depth[i]=0;
	}
	for(int i=0;i<n-1;i++){
		ll from,to;
		cin >> from>>to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}


	for(int i=0;i<q;i++){
		nodes.clear();
		res.clear();

		cin>>k;
		ll m;
		cin>> m;
		for(int j=0;j<m;j++){
			ll nod;
			cin >> nod;
			nodes[nod]=true;
		}
		maxi=0;
		dfs(1);
		cout << res[maxi]<<'\n';
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