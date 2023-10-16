#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isS(ll n) {
    ll k = sqrt(n);
    return (k*k == n);
}

vector<pair<long long,long long>> sq(ll n) {
    vector<pair<long long,long long>> v;
    for (long long i = 1; i < n; i++) {
        if (isS(1LL * n*n-i*i)) {
            v.push_back({i,sqrt(n*n-i*i)});
            v.push_back({-i,sqrt(n*n-i*i)});
        }
    }
    return v;
}

int main(){
    ll a,b; cin >> a >> b;
    vector<pair<long long,long long>> v1 = sq(a-1);
    vector<pair<long long,long long>> v2 = sq(b-1);
    long long ans = 0;
    for (long long i = 0; i < v1.size(); i++) {
        for (long long j = 0; j < v2.size(); j++) {
            auto [x1,y1] = v1[i];
            auto [x2,y2] = v2[j];
            if (1LL*x1*x2 + 1LL*y1*y2 == 0) {
                ans++;
            }
        }
    }
    if (a == b) {
        ans/= 2;
    }
    if (a != b)
        cout << ans+2;
    else
        cout << ans+1;
}