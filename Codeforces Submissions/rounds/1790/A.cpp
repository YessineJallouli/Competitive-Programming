#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin >> T;
    while (T--) {
        string s = "314159265358979323846264338327";
        string ch; cin >> ch;
        for (int i = 0; i < ch.size(); i++) {
            if (ch[i] != s[i]) {
                cout << i << '\n';
                break;
            }
            if (i == ch.size()-1) {
                cout << ch.size() << '\n';
            }
        }
    }
}