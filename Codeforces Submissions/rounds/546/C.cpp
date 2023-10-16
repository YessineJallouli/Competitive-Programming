#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> v1;
    int k1,k2;
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int x; cin >> x;
        v1.push_back(x);
    }
    vector<int> v2;
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int x; cin >> x;
        v2.push_back(x);
    }
    map<pair<vector<int>, vector<int>>, bool> state;
    int nbRound = 0;
    while (true) {
        if (state.count({v1,v2})) {
            cout << -1 << '\n';
            break;
        }
        if ((int) v1.size() == 0) {
            cout << nbRound << ' ' << 2 << '\n';
            break;
        } else if ((int) v2.size() == 0) {
            cout << nbRound << ' ' << 1 << '\n';
            break;
        }
        nbRound++;
        state[{v1,v2}] = true;
        if (v1[0] < v2[0]) {
            v2.push_back(v1[0]);
            v2.push_back(v2[0]);
            v2.erase(v2.begin());
            v1.erase(v1.begin());
        } else {
            v1.push_back(v2[0]);
            v1.push_back(v1[0]);
            v2.erase(v2.begin());
            v1.erase(v1.begin());
        }
    }
}