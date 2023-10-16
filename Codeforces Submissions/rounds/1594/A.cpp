#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

const int mx = 7e5+7;
int col[mx];
bool vis[mx];

int ans = 0;

int n;

vector<vector<int>> graph(mx);
bool bipartie;

int NB1 = 0, NB2 = 0;

void check_bip(ll src, ll coler){
    if(vis[src])return ;
    vis[src]=1;
    col[src]=coler;
    if (src > 0 && src <= n) {
        NB1+= (coler == 0);
        NB2+=(coler == 1);
    }
    for(auto t: graph[src]){
        if(vis[t]){
            if(col[t]==col[src]){
                bipartie=false;
                return ;
            }
            continue;
        }
        check_bip(t,1-coler);
    }
}

int main() {
    SaveTime
    int T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        cout << -n+1 << ' ' << n << '\n';
    }
}