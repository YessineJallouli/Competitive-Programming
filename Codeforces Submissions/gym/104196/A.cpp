// WE ARE NOT HERE TO TAKE PART , WE ARE HERE TO TAKE OVER
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
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
const int NAX=1e5+5;


int dp[NAX];

ll go(int val){


    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=val;i++){
        int mini=i;
        debug() << imie(mini);
        for(int j=1;j<i;j++){
            mini=min(mini,dp[j]+dp[i-j]);
            debug() << imie(dp[j]) imie(dp[i-j]) imie(j) imie(i);
        }

        for(ll j=2;j*j<=i;j++){
            if(i%j!=0) continue;
            mini=min(mini,dp[j]+dp[i/j]);
            debug() << imie(mini) imie("inse") imie(i);
        }

        ll digits=log10(i)+1;

        for(int j=1;j<=digits;j++){
            ll firstpart=i/pow(10,j);
            ll secondpart=i%(int)pow(10,j);
            ll sz1=log10(firstpart)+1;
            ll sz2=log10(secondpart)+1;

            if(secondpart!=0 && sz1+sz2==digits){
                debug() << imie("ha") imie(firstpart) imie(secondpart) imie(dp[firstpart]) imie(dp[secondpart]);
                mini=min(dp[firstpart]+dp[secondpart],mini);
            }
        }

        dp[i]=mini;

    }
    debug() << imie(val);
	return dp[val];
}


void solve(){

	cin >> n;
    debug() << imie(n);
	for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
	cout << go(n) << "\n";

	
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