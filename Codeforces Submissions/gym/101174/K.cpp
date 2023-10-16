#include "bits/stdc++.h"
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vchr;
typedef vector<string> vstr;
typedef vector<vi> vvi;
typedef vector<vchr> vvchr;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define endl '\n';
#define yes cout << "YES\n";
#define no  cout << "NO\n";
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937_64 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
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
#define MP make_pair
#define PB push_back
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define For(i, n) for(int i=0; i < n; ++i)
#define Forr(i, n, p) for(int i=p; i < n; ++i)
#define dd(arr) For(i, arr.size()) cout << arr[i] << " "; cout << endl;


struct Point{
	int x, y, z;
	void read(){
		cin >> x >> y >> z;
	}
	bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};


map<ppii, set<ppii>> graph;
map<pii, set<pii>> floorGraph;
map<ppii, int> visited;
map<pii, int> visitedF;

bool dfs(ppii v, ppii par) {
	visited[v] = true;
	for (ppii u : graph[v]) {
		if(u == par) continue;
		if (visited[u]) {
			return true;
		}
		if (dfs(u, v))
			return true;
	}
	return false;
}

bool floordfs(pii v, pii par) {
	visitedF[v] = true;
	for (pii u : floorGraph[v]) {
		if(u == par) continue;
		if (visitedF[u]) {
			return true;
		}
		if (floordfs(u, v))
			return true;
	}
	return false;
}


vector<pair<Point, Point>> arr;
void addEdge(Point p1, Point p2){
	ppii x = {{p1.x, p1.y}, p1.z};
	ppii y = {{p2.x, p2.y}, p2.z};
	graph[x].insert(y);
	graph[y].insert(x);
}

void addEdgeFloor(Point p1, Point p2){
	pii x = {p1.x, p1.y};
	pii y = {p2.x, p2.y};
	if(x == y) return;
	floorGraph[x].insert(y);
	floorGraph[y].insert(x);
}



void solve(){
	int k; cin >> k;
	arr.resize(k);
	For(i, k){
		arr[i].first.read();
		arr[i].second.read();
		addEdge(arr[i].first, arr[i].second);
		addEdgeFloor(arr[i].first, arr[i].second);
	}
	bool closed = false;
	bool floorClosed = false;
	For(i, k){
		Point p1 = arr[i].first;
		ppii x = {{p1.x, p1.y}, p1.z};
		if(!visited[x] && dfs(x, {{-1, -1}, -1})){
			closed = 1;
		}
		pii xx = {p1.x, p1.y};
		if(!visitedF[xx] && floordfs(xx, {-1, -1})){
			floorClosed = 1;
		}
	}
	if(closed){
		cout << "True closed chains" << endl;
	}else{
		cout << "No true closed chains" << endl;
	}
	if(floorClosed){
		cout << "Floor closed chains" << endl;
	}else{
		cout << "No floor closed chains" << endl;
	}


}

int main(){
	fastio;
	// cout << setprecision(9);
	// cout << fixed;
	// freopen("input.in", "r", stdin);
	// freopen("output.out", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--)
		solve();
	return 0;
}