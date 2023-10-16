#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    ll a,b; cin >> a >> b;
    vector<pair<int,ll>> ans;
    while (a != 0 && b != 0) {
        if (abs(a) > abs(b)) {
            ll k = abs(a) / abs(b);
            if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
                ll a1 = a-k*b;
                ll a2 = a-(k+1)*b;
                if (abs(a1) < abs(a2)) {
                    a = a1;
                    ans.emplace_back(1, -k);
                }
                else {
                    a = a2;
                    ans.emplace_back(1, -(k+1));
                }
            }
            else {
                ll a1 = a+k*b;
                ll a2 = a+(k+1)*b;
                if (abs(a1) < abs(a2)) {
                    a = a1;
                    ans.emplace_back(1, k);
                }
                else {
                    a = a2;
                    ans.emplace_back(1, k+1);
                }
            }
        }
        else {
            ll k = abs(b) / abs(a);
            if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
                ll b1 = b-k*a;
                ll b2 = b-(k+1)*a;
                if (abs(b1) < abs(b2)) {
                    b = b1;
                    ans.emplace_back(2, -k);
                }
                else {
                    b = b2;
                    ans.emplace_back(2, -(k+1));
                }
            }
            else {
                ll b1 = b+k*a;
                ll b2 = b+(k+1)*a;
                if (abs(b1) < abs(b2)) {
                    b = b1;
                    ans.emplace_back(2, k);
                }
                else {
                    b = b2;
                    ans.emplace_back(2, k+1);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [x,y] : ans)
        cout << x << ' ' <<  y << '\n';
}