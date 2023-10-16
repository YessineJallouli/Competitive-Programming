#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
ll pr[N];

ll getSum(int a, int b) {
    return pr[b+1]-pr[a];
}


int main() {
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pr[0] = 0;
    sort(a, a+n);
    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i-1]+a[i-1];
    }
    int mx = 0;
    int val = -1;
    for (int i = 0; i < n; i++) {
        int l = 0, r = i;
        int idAns = -1;
        while (l <= r) {
            int m = (l+r)/2;
            ll sum = getSum(m,i);
            int nbElements = i-m+1;
            ll nbOperations = 1LL*a[i]*nbElements - sum;
            if (nbOperations <= k) {
                idAns = m;
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        int nbF = i-idAns+1;
        if (nbF > mx) {
            val = a[i];
            mx = nbF;
        }
    }
    cout << mx << ' ' << val;
}