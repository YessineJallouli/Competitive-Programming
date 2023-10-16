//
// Created by yessine on 1/10/23.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int n = s.size();
        int id = -1;
        for (int i = 1; i < n-1; i++) {
            if (s[i] == 'a')
                id = i;
        }
        if (id != -1) {
            for (int i = 0; i < id; i++) {
                cout << s[i];
            }
            cout << " a ";
            for (int i = id+1; i < n; i++) {
                cout << s[i];
            }
            cout << '\n';
        }
        else {
            cout << s[0] << ' ';
            for (int i = 1; i < n-1; i++) {
                cout << s[i];
            }
            cout << ' ';
            cout << s[n-1] << '\n';
        }
    }
}