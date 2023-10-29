//100%
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    cin.ignore();
    map<char,int> m;
    m['T'] = 10; m['J'] = 11; m['Q'] = 12; m['K'] = 13; m['A'] = 14;

    while (T--) {
        string s; getline(cin, s);
        deque<int> A;
        deque<int> B;
        for (int i = 0; i < s.size(); i+= 2) {
            char c = s[i];
            if (c >= '2' && c <= '9') {
                A.push_back(c-'0');
            }
            else {
                A.push_back(m[c]);
            }
        }
        getline(cin, s);
        for (int i = 0; i < s.size(); i+= 2) {
            char c = s[i];
            if (c >= '2' && c <= '9') {
                B.push_back(c-'0');
            }
            else {
                B.push_back(m[c]);
            }
        }
        int nbIterations = 1e6;
        while (nbIterations--) {
            if (A.empty() || B.empty())
                continue;
            if (A[0] == B[0]) {
                int k = A[0];
                A.pop_front();
                B.pop_front();
                A.push_back(k);
                B.push_back(k);
            }
            else if (B[0] < A[0]) {
                A.pop_front();
                A.push_back(B[0]);
                B.pop_front();
            }
            else {
                B.pop_front();
                B.push_back(A[0]);
                A.pop_front();
            }
        }
        if (A.empty()) {
            cout << "player 2\n";
        }
        else if (B.empty()) {
            cout << "player 1\n";
        }
        else {
            cout << "draw\n";
        }

    }
}
