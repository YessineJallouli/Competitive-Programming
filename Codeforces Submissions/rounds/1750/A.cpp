// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (a[0] == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}