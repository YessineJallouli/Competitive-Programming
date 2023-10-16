#include <vector>
#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string a,b; cin >> a >> b;
        int nb[26];
        memset(nb, 0, sizeof nb);
        for (int i = 0; i < a.size(); i++) {
            nb[a[i]-'A']++;
        }
        bool ans = true;
        for (int i = 0; i < b.size(); i++) {
            nb[b[i]-'A']--;
            if (nb[b[i]-'A'] < 0)
                ans = false;
        }
        if (! ans) {
            cout << "NO\n";
            continue;
        }
        while (a.size() != b.size()) {
            for (int i = 0; i < a.size(); i++) {
                if (nb[a[i]-'A'] > 0) {
                    nb[a[i]-'A']--;
                    a.erase(i, 1);
                    break;
                }
            }
        }
        if (a == b) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}