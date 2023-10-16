//
// Created by ramizouari on 14/10/2021.
//

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    string s; cin >> s;
    int n = s.size();
    int serve = 1;
    int s1 = 0, s2 = 0;
    int nb1 = 0, nb2 = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'Q') {
            if (nb1 == 2) {
                cout << nb1 << " (winner) - " << nb2 << '\n';
            }
            else if (nb2 == 2) {
                cout << nb1 << " - " << nb2 << " (winner)" << '\n';
            }
            else {
                cout << nb1 << " (" << s1;
                if (serve == 1) {
                    cout << '*';
                }
                cout << ") - " << nb2 << " (" << s2;
                if (serve == 2) {
                    cout << '*';
                }
                cout << ")\n";
            }
        }
        else if (c == 'R') {
            if (nb1 == 2 || nb2 == 2)
                continue;
            if (serve == 1) {
                s2++;
                serve = 2;
            }
            else {
                serve = 1;
                s1++;
            }
        }
        else if (c == 'S') {
            if (nb1 == 2 || nb2 == 2)
                continue;
            if (serve == 1)
                s1++;
            else
                s2++;
        }
        if (s1 == 10) {
            nb1++;
            s1 = s2 = 0;
        }
        if (s2 == 10) {
            nb2++;
            s1 = s2 = 0;
        }
        if (s1 >= 5 && s1-s2 >= 2) {
            nb1++;
            s1 = s2 = 0;
        }
        if (s2 >= 5 && s2-s1 >= 2) {
            nb2++;
            s1 = s2 = 0;
        }
    }
}