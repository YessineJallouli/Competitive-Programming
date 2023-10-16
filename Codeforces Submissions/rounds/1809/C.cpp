#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        memset(a, 0, sizeof a);
        for (int i = 0; i < n; i++) {
            if (k >= n-i) {
                a[i] = 1;
                k-= (n-i);
            }
        }
        reverse(a, a+n);
        int maximumSum = 0;
        int minimumSum = 0;
        int sumMx = 0;
        int sumMn = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]) {
                a[i] = abs(minimumSum)+1;
                sumMx+= a[i];
                sumMn+= a[i];
                if (sumMn > 0) {
                    sumMn = 0;
                }
                maximumSum = max(maximumSum, sumMx);
                minimumSum = min(minimumSum, sumMn);
            }
            else {
                a[i] = -maximumSum-1;
                sumMx+= a[i];
                sumMn+= a[i];
                if (sumMx < 0)
                    sumMx = 0;
                maximumSum = max(maximumSum, sumMx);
                minimumSum = min(minimumSum, sumMn);
            }
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}