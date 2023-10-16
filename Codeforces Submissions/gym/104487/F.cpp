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
vector<pair<ll,ll>> values;
bool check(int mid,ll secs){
	if(values[mid].first<=secs) return true;
	return false;
}
void solve(){

	values.clear();
	cin >> n >>q;
	deque<int> deq;
	set<pair<ll,ll>> s; // value and 0 -> left ; 1 -> right;

	for(int i=0;i<n;i++){
		ll val;
		cin >> val;
		deq.push_back(val);
	}

	if(n==1){
		ll v=deq.at(0);
		for(int i=0;i<q;i++){
			ll sec;
			cin >> sec;
			if(sec<v){
				cout << 1 << "\n";

			}else{
				cout << 0 << "\n";
			}
		}	
		return;
	}
	int left=deq.front();
	deq.pop_front();
	
	int right=deq.back();
	deq.pop_back();
	s.insert({left,0});
	s.insert({right,1});
	ll seconds=0;
	int currval=0;
	while((int)deq.size()>0||!s.empty()){
		
		pair<ll,ll> p=(*s.begin());
		currval++;
		seconds+=p.first;
		ll other=p.first;
		values.push_back({seconds,currval});

		s.erase(p);
		int ellitnaha=p.second;
		if(s.size()!=0){
			p=(*s.begin());
			s.erase(p);
			p.first-=other;
			s.insert(p);
		}

		if((int)deq.size()!=0){
			if(ellitnaha==0){
			s.insert({deq.front(),0});
				deq.pop_front();
		}else{
			s.insert({deq.back(),1});
			deq.pop_back();
		}
		}

	}
	
	debug() << imie("here");
	debug() << imie(values);
	for(int i=0;i<q;i++){
		ll secs;
		cin >> secs;
		debug() << imie(i) imie(secs);
		int l=0;
		int r=(int)values.size()-1;
// k+1 dima False (invariant;
// l=-1 tnejem tbadelha ama nejmou nhotoha =0 mathalan el
// lehn khtarna =-1 bech ken matbadletech naarfou eli mafama hata solution ! 
		while(l<r){
		int mid=l+(r-l+1)/2;	
			if(check(mid,secs)){
			//cout << mid << endl;
			l=mid;
			}else{
			r=mid-1;
			}
		}

		if(values[l].first>secs){
			cout << n << "\n";
		}else{
			cout << n-values[l].second<<'\n';
		}
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