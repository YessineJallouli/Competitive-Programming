#include <bits/stdc++.h>
#define ll __int128
#define pi pair<ll,ll>
using namespace std;


int main() {
    //cout << ULLONG_MAX;
    long long r,s,m,d,n; cin >> r >> s >> m >> d >> n;
    vector<vector<ll>> starter(s);
    vector<vector<ll>> menu(m);
    vector<vector<ll>> dinner(d);

    long long b[r+1];
    for (ll i = 1; i <= r; i++) {
        cin >> b[i];
    }

    for (ll i = 0; i < s; i++) {
        long long k; cin >> k;
        for (ll j = 0; j < k; j++) {
            long long ing; cin >> ing;
            starter[i].push_back(ing);
        }
    }

    for (ll i = 0; i < m; i++) {
        long long k; cin >> k;
        for (ll j = 0; j < k; j++) {
            long long ing; cin >> ing;
            menu[i].push_back(ing);
        }
    }

    for (ll i = 0; i < d; i++) {
        long long k; cin >> k;
        for (ll j = 0; j < k; j++) {
            long long ing; cin >> ing;
            dinner[i].push_back(ing);
        }
    }

    map<pair<ll,ll>,ll> incompatible;

    for (ll i = 0; i < n; i++) {
        long long x,y; cin >> x >> y;
        if (x > y) {
            swap(x,y);
        }
        x--; y--;

        incompatible[{x,y}] = true;
        incompatible[{y,x}] = true;
    }
    ll ans = 0;
    ll inf = 1e18;
    for (ll i = 0; i < s; i++) {

        for (ll j = 0; j < m; j++) {
            for (ll k = 0; k < d; k++) {
                if (ans > inf)
                    break;
                set<ll> g;
                for (ll ing : starter[i])
                    g.insert(ing);
                for (ll ing : menu[j])
                    g.insert(ing);
                for (ll ing : dinner[k])
                    g.insert(ing);

                ll id1 = i;
                ll id2 = s+j;
                ll id3 = s+m+k;
                if (incompatible.count({id1, id2}) || incompatible.count({id2, id3}) || incompatible.count({id1, id3}))
                    continue;
                ll cont = 1;
                for (ll ing : g) {
                    cont = cont * b[ing];
                    if (cont > inf)
                        break;
                }
                if (cont > inf) {
                    ans = inf+1;
                    break;
                }
                else {
                    ans+= cont;
                }
            }
        }
    }

    if (ans > inf) {
        cout << "too many";
    }
    else {
        std::vector<int> S;
        auto r=ans;
        while(r)
        {
            S.push_back(r%10);
            r/=10;
        }
        std::reverse(S.begin(),S.end());
        if(S.empty())
            S.push_back(0);
        for(auto s:S)
            std::cout << s;
        std::cout << '\n';
    }

}