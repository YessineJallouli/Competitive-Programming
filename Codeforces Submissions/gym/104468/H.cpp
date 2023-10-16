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
struct node {
	ll sum;
	ll lazy;
	bool update;
	node(){
		sum=0;
		lazy=0;
		update=false;
	}

	node(ll _sum,ll _lazy,bool _update){
		sum=_sum;
		lazy=_lazy;
		update=_update;
	}
};

class LazySegTree{
	private:
		int n;
		vector<ll> A;
		vector<node> st;
		int left(int index) {return 2*index;}
		int right(int index) {return 2*index+1;}
		void propagate(int index,int l,int r){
			if(!st[index].update) return;
			if(l!=r){
				st[left(index)].update=true;
				st[right(index)].update=true;
				st[left(index)].lazy+=st[index].lazy;
				st[right(index)].lazy+=st[index].lazy;
				int mid=(l+r)/2;
				st[left(index)].sum+= (mid-l+1) * st[index].lazy;
				st[right(index)].sum+= (r-mid) * st[index].lazy;
			}
			st[index].lazy=0;
			st[index].update=false;
		}

		node merge(node &l,node &r){
			return node(l.sum+r.sum,0,false);
		}

		void build(int index,int L,int R){
			if(L==R){
				st[index].sum=A[L];
				return;
			}
			int mid=(L+R)/2;
			build(left(index),L,mid);
			build(right(index),mid+1,R);
			st[index]=merge(st[left(index)],st[right(index)]);
		}

		void update(int index,int L,int R,int Lx,int Rx,int v){ // on ajoute v lel range kemel
			propagate(index,L,R); // I m sure eli maandi hata hkeya fou9i fel path edheka mahich updated correctly khater 9a3ed nemchi et ndez fel updates donc impo haja fou9i a9dem meni nsitha..
			
			if(Lx>R || Rx<L) return;

			if(R<=Rx && L>=Lx){
				st[index].update=true;
				st[index].lazy+=v;
				st[index].sum+=(R-L+1)*1ll*v;
				
				return;
			}

			int mid=(L+R)/2;
			update(left(index),L,mid,Lx,Rx,v);
			update(right(index),mid+1,R,Lx,Rx,v);
			st[index]=merge(st[left(index)],st[right(index)]);
		}

		ll getSum(int index,int L,int R,int Lx,int Rx){
				propagate(index,L,R);
				if(Lx>R || Rx<L) return 0;

				if(R<=Rx && L>=Lx){
				
				return st[index].sum;
				}		
				int mid=(L+R)/2;
				ll leftVal=getSum(left(index),L,mid,Lx,Rx);
				ll rightVal=getSum(right(index),mid+1,R,Lx,Rx);
				return leftVal+rightVal;

		}

		public:
			LazySegTree(int sz):n(sz),A(n),st(4*n){

			};
			LazySegTree(vector<ll>& initial):LazySegTree((int)initial.size()){
				A=initial;
				build(1,0,n-1);
			}
			void update(int i, int j, int val) { update(1, 0, n-1, i, j, val);}

			ll getSum(int l,int r){
				return getSum(1,0,n-1,l,r);
			}

};


const int NAX=2e5+5;
vector<int> v[NAX];
vector<int> val(NAX);
vector<int> color(NAX);
vector<int> leftt(NAX);
vector<int> rightt(NAX);
void solve(){

	cin >> n;
	for(int i=0;i<n;i++){
		cin >> val[i];
	}

	for(int i=0;i<n;i++){
		cin >> color[i];
	}

	for(int i=0;i<n;i++){
		v[color[i]].push_back(val[i]);
	}

	vector<ll> A;
	int currl=0;

	for(int i=0;i<NAX;i++){
		if((int)v[i].size()==0) continue;
		leftt[i]=currl;
		vector<int>& vv=v[i];
		for(auto el:vv){
			currl++;
			A.push_back(el);
		}
		rightt[i]=currl-1;
	}

	LazySegTree st(A);
	int sz=(int)A.size();
	cin >> q;
	for(int i=0;i<q;i++){
		ll tp,col,te;
		cin >> tp >> col >> te;
		if(tp==1){
			int lefti=leftt[col];
			int righti=rightt[col];
			if(lefti>0){
				st.update(0,lefti-1,te);
			}
			if(righti<sz-1){
				st.update(righti+1,sz-1,te);
			}

		}else{
			int l=leftt[col];
			int r=rightt[col];
			while(l<r){
				int mid=l+(r-l+1)/2;	
				ll v=st.getSum(leftt[col],mid);
				if(v<=te){
					l=mid;
				}else{
					r=mid-1;
				}

			}

			if(st.getSum(leftt[col],l)>te){
				cout << 0 << "\n";
			}else{
				cout << l-leftt[col]+1<<'\n';
			}

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