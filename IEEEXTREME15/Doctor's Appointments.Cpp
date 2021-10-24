#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < pair < int, int > > st[maxn];
vector < int > ed[maxn];



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0 ; i <= n ; ++i){
            st[i].clear();
            ed[i].clear();
        }
        for(int i = 0 ; i < n ; ++i){
            int l, r;
            cin >> l >> r;
            st[l].push_back({r, i + 1});
            ed[r + 1].push_back(i + 1);
        }
        vector < int > ans;
        bool can = true;
        set < int > scheduled;
        priority_queue < pair < int, int > > pq;
        for(int i = 1 ; i <= n && can; ++i){
            for(auto done: ed[i])
                if(scheduled.find(done) == scheduled.end()){
                    can = false;
                    break;
                }
            for(auto start: st[i]){
                pq.push({-start.first, start.second});
            }
            if(pq.empty()){
                can = false;
                break;
            }
            auto u = pq.top();
            pq.pop();
            ans.push_back(u.second);
            scheduled.insert(u.second);
        }
        if(!can || sz(scheduled) != n){
            cout << "impossible\n";
            continue;
        }
        for(auto pt: ans) cout << pt << ' ';
        cout << '\n';
    }

    return 0;
}

/*

1,2 // 1,3 // 2,4 // 3,3

*/
