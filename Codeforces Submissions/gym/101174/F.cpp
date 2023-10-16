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
int E;
const int NAX=1e5+5;

ll expected[NAX];
ll rankk[NAX];
ll res[NAX];

vector<int> adj[NAX];

ll manager=-1;
int tin[NAX];
int tout[NAX];
int bigch[NAX];
int timer=0;
vector<int> eulertour;
int dpsz[NAX];
vector<ll> A(NAX);
class SegmentTree{
	private: 
		int n;
		vector<ll> A,st;
	
	int l(int p) {return p<<1;}
	int r(int p) {return (p<<1)+1;}
	
	void build(int p,int L,int R){
		if(L==R){
			st[p]=A[L];
		}else{
			int mid=(R+L)/2;
			build(l(p),L,mid);
			build(r(p),mid+1,R);
			st[p]=st[l(p)]+st[r(p)];
		}
	}
	void update(int p,int L,int R,ll val, int X){
		if(X==R&&L==X){
			st[p]=val;
			return;
		}
		if(R<X || L>X) return;
		int mid=(R+L)/2;
		update(l(p),L,mid,val,X);
		update(r(p),mid+1,R,val,X);
		st[p]=st[l(p)]+st[r(p)];
	}
	ll RSQ(int p,int L,int R,int LX,int RX){
		if(LX<=L&&R<=RX) return st[p];
		if(R<LX || L>RX) return 0;
		ll currVal=RSQ(l(p),L,(L+R)/2,LX,RX)+RSQ(r(p),(L+R)/2 +1 ,R,LX,RX);
		return currVal;
	}
	public:
		SegmentTree(int sz) : n(sz), st(4*n) {}
		SegmentTree(const vector<ll> &initialA): SegmentTree((int)initialA.size()){
			A=initialA;
			build(1,0,n-1);
		}
		void update(int X,ll val){
			//debug() << imie(X) imie(val);
			update(1,0,n-1,val,X);
		}
		ll RSQ(int LX,int RX){
			
			return RSQ(1,0,n-1,LX,RX);
		}
		
	
};
SegmentTree st(A);
void dfs(int node){
	tin[node]=timer;
	timer++;
	eulertour.push_back(node);
	int maxi=0;
	dpsz[node]=1;
	int index=-1;
	for(auto el:adj[node]){
		dfs(el);
		dpsz[node]+=dpsz[el];
		if(maxi<dpsz[el]){
			maxi=dpsz[el];
			index=el;
		}
	}
	bigch[node]=index;
	tout[node]=timer-1;
}
void add(int node){

	ll rankme=rankk[node];
	ll tec=expected[node];
	ll curres=st.RSQ(rankme-1,rankme-1);
	curres+=tec;
	st.update(rankme-1,curres);
	debug() << imie(st.RSQ(0,NAX-1));
}
void remove(int node){
	
	ll rankme=rankk[node];
	ll tec=expected[node];
	ll curres=st.RSQ(rankme-1,rankme-1);
	curres-=tec;
	debug() << imie(tec);
	st.update(rankme-1,curres);
}
void solverec(int node,bool keep,int par){
	for(auto el:adj[node]){
		if(el==par||el==bigch[node])continue;
		solverec(el,false,node);
	}
	if(bigch[node]!=-1){
		solverec(bigch[node],true,node);
	}
	for(auto el:adj[node]){
		if(el==par||el==bigch[node]) continue;
		for(int i=tin[el];i<=tout[el];i++){
			add(eulertour[i]); // place in eulertour;
		}
	}
	debug() << imie("hii") imie(node) imie(rankk[node]-1);
	ll time=0;
	if(rankk[node]-2>=0){
		time=st.RSQ(0,rankk[node]-2);
	} 
	debug()<<imie(st.RSQ(0,NAX-1));
	res[node]=time;
	
	add(node);
	if(!keep){
		for(int i=tin[node];i<=tout[node];i++){
			remove(eulertour[i]);
		}
	}
	
}
void solve(){
	
	cin >> E;

	for(int i=0;i<E;i++){
		ll boss,tec,exp;
		cin >> boss >> tec >> exp;
		if(boss!=-1){
			boss--;
			adj[boss].push_back(i);
		}else{
			manager=i;
		}
		rankk[i]=tec;
		expected[i]=exp;
	}

	dfs(manager);

	debug() << imie(eulertour);
	solverec(manager,1,-1);
	for(int i=0;i<E;i++){
		assert(res[i]>=0);
	}
	for(int i=0;i<E;i++){
		
		cout << res[i]<<"\n";
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