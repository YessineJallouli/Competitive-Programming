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
	ll k;
	cin >> n >>k;
	vector<bool> star(n,false);
	vector<ll> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}

	vector<bool> levelok(k,false);
	ll total=0;
	ll number=0;
	ll mini=1e9;
	for(int i=k-1;i>=0;i--){
		ll inside=0;
		vector<ll> stouraadd;
		bool found=false;
		for(int j=0;j<n;j++){
			if(!(vec[j]&(1<<i))){
				if(star[j]){
					found=true;
					break;
				}else{
					stouraadd.push_back(j);
				}
			}
		}
		if(found) continue;

		for(auto el:stouraadd){
			star[el]=true;
			vec[el]|=(1<<i);
		}
		total+=(1<<i);
		levelok[i]=true;
		mini=min(mini,(ll)i);
	}

	for(int i=0;i<n;i++){
		if(star[i]) continue;
		for(int j=0;j<k;j++){
			if(levelok[j]) continue;
			star[i]=true;
		}
	}

	for(int i=0;i<n;i++){
		number+=!star[i];
	}

	if(number){
		cout << total-(1<<mini)<<'\n';
	}else{
		cout << total<<'\n';
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