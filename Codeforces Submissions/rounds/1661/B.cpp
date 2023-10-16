#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 32768;
int puissance[N+1];

int main() {
    int p = 1;
    int nb = 0;
    puissance[1] = 0;
    for (int i = 1; i <= N; i++) {
        if (i > p) {
            p*= 2;
            nb++;
            puissance[p] = nb;
        }
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        int res = INT_MAX;
        for (p = 1; p <= N; p*= 2) {
            int k = (p-(x%p))%p;
            res = min(res, puissance[N/p]+k);
        }
        cout << res << ' ';
    }
}