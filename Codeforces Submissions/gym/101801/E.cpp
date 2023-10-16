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
const int NAX=105;
ll dp[NAX][NAX][NAX];
ll work(int index,int currxor,int disp){
	//debug() << imie(index) imie(currxor) imie(disp);

	if(dp[index][currxor][disp]!=-1) return dp[index][currxor][disp];
	if(disp<0){
		return 0;
	}

	ll val=0;
	if(disp==0 && currxor!=0) val=1;
	for(int i=1;i<=disp;i++){
		val+=work(index+1,currxor^i,disp-i);
		val%=prime;
	}
	debug() << imie(val) imie(index) imie(currxor) imie(disp);
	return dp[index][currxor][disp]=val;
}



void solve(){
	cin >> n;

	ll v=0;
	memset(dp,-1,sizeof dp);

	
	for(int i=1;i<=n;i++){
		 work(0,i,n-i);
	}

	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				debug() << imie(dp[i][j][k]) imie(i) imie(j) imie(k);
			}
		}
	}	


	for(int j=1;j<=n;j++){
		for(int i=0;i<=n;i++){
			v+=max(dp[0][j][i],0ll);
			v%=prime;
		}
	}

	cout << v <<'\n';

	

	
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