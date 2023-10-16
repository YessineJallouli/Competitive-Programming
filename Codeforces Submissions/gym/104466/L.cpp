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
struct node{
	// "("
	ll toRight;
	// ")"
	ll toLeft;
};
vector<node> tree;
vector<node> vec;
class HashedString {
  public:
	// change M and B if you want
	static const ll M = (1LL << 61) - 1;
	static const ll B;

	// pow[i] contains B^i % M
	static vector<ll> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<ll> p_hash;

	__int128 mul(ll a, ll b) { return (__int128)a * b; }
	ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) {
			pow.push_back(mod_mul(pow.back(), B));
		}
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}

	ll getHash(int start, int end) {
		ll raw_val =
			p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
node getNode(int toRight,int toLeft){
	node nd=node();
	nd.toRight=toRight;
	nd.toLeft=toLeft;
	return nd;
}
node merge(node left,node right){
	ll mini=min(left.toRight,right.toLeft);
	
	return getNode(left.toRight+right.toRight-mini,left.toLeft+right.toLeft-mini);
}
node query(int node,int node_low,int node_high,int query_low,int query_high){
    if(node_high<query_low) return getNode(0,0);
    if(node_low>query_high) return getNode(0,0);
    if(node_low>=query_low && node_high<=query_high) return tree[node];
    int mid=(node_low+node_high)/2;
 
    return merge(query(2*node,node_low,mid,query_low,query_high),query(2*node+1,mid+1,node_high,query_low,query_high));
}
void buildSeg(){
	
	
	for(int i=n-1;i>=1;i--){
		tree[i]=merge(tree[2*i],tree[2*i+1]);
	}
	
}
string s;

void solve(){

	cin >> s;
	HashedString hs(s);
	n=(int)s.size();
	debug() << imie(s);
	vec.resize(n);
	for(int i=0;i<(int)s.length();i++){
		if(s[i]==')') vec[i]=getNode(0,1);// toright, to left
		if(s[i]=='(') vec[i]=getNode(1,0);
	}
	int tempN=n;
	while(__builtin_popcount(n)!=1){
		n++;
		vec.push_back(getNode(0,0));
	}
	tree.resize(2*n);
for(int i=0;i<n;i++){
		tree[i+n]=vec[i];
		if(i>=s.length()) tree[n+i]=getNode(0,0);
		
	}
	buildSeg();
	for(int i=0;i<tempN-1;i++){
		node t1=query(1,0,n-1,0,i);
		node t2=query(1,0,n-1,i+1,n-1);

		if(t2.toLeft>0) continue;
		if(t1.toRight>0) continue;
		if(t2.toRight==t1.toLeft){
			debug() << imie(t2.toLeft) imie(t2.toRight) imie(t1.toRight) imie(t1.toLeft) imie(i);
			ll hashpart1=hs.getHash(i+1,tempN-1);
			ll hashpart2=hs.getHash(0,i);
			ll firstt=hs.getHash(0,tempN-(i+1)-1);
			ll firstt1=hs.getHash(tempN-(i+1),tempN-1);
			if(hashpart1==firstt && firstt1==hashpart2) continue;
			debug() << imie(i+1) imie(tempN-1) imie(tempN-(i+1));
			for(int j=i+1;j<tempN;j++){
				cout << s[j];
			}
			for(int j=0;j<=i;j++){
				cout << s[j];
			}
			cout <<"\n";
			return;
		}



	}

	cout << "no"<<"\n";




	
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
//	cin >> tc;
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