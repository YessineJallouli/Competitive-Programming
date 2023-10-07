#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

set<vector<int>> s;
int mn = INT_MAX;

vector<int> bestV;

void solve(vector<int> &v, int sum) {
    vector<int> k;
    for (int i : v)
        k.push_back(i);
    sort(k.begin(),k.end());
    if (s.count(k))
        return;
    s.insert(k);
    int n = (int) v.size();
    if (41-sum+n < mn) {
        mn = 41-sum+n;
        bestV.clear();
        for (int i : v)
            bestV.push_back(i);
        for (int i = sum; i < 41; i++)
            bestV.push_back(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int S = sum-v[i]-v[j]+v[i]*v[j];
            if (S <= 41) {
                vector<int> kk;
                for (int h = 0; h < n; h++) {
                    if (h != i && h != j)
                        kk.push_back(v[h]);
                }
                kk.push_back(v[i]*v[j]);
                solve(kk, S);
            }
        }
    }
}


void solve() {
    s.clear();
    mn = INT_MAX;
    int p; cin >> p;
    int sum = 0;
    vector<int> v;

    int P = p;
    for (int i = 2; i*i <= P; i++) {
        while (p%i == 0) {
            p/= i;
            v.push_back(i);
            sum+= i;
        }
    }
    if (p != 1) {
        sum += p;
        v.push_back(p);
    }
    if (sum > 41) {
        cout << -1 << '\n';
        return;
    }
    solve(v,sum);

    cout << bestV.size() << ' ';
    for (int i : bestV)
        cout << i << ' ';
    cout << '\n';

}

int main() {
    SaveTime
    freopen("sum_41_chapter_2_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T; cin >> T;
    for (int ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        solve();
    }
}