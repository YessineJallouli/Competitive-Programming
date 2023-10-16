#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        deque<char> d;
        for (char c : s) {
            d.push_back(c);
        }
        for (int i = 0; i < n; i++) {
            if (d.empty())
                break;
            if (d[0] != d.back()) {
                d.pop_back();
                d.pop_front();
            }
        }
        cout << d.size() << '\n';
    }
}