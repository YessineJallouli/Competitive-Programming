#include <bits/stdc++.h>
using namespace std;

mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

int cnt[40000000];
int offset = 34000000;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int p = 0; p < 2; p++) {
        for (int diff = 0; diff < 340; diff++) {
            int b[n];
            for (int i = 0; i < n; i++)
                b[i] = a[i]-i*diff;
            for (int i = 0; i < n; i++) {
                cnt[b[i] + offset]++;
                res = max(res, cnt[b[i] + offset]);
            }
            for (int i = 0; i < n; i++)
                cnt[b[i]+offset]--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = max(0, i-340); j < i; j++) {
                int k = a[i]-a[j];
                if (k < 0 || k%(i-j))
                    continue;
                k/= (i-j);
                cnt[k]++;
                res = max(res, cnt[k]+1);
            }
            for (int j = max(0, i-340); j < i; j++) {
                int k = a[i]-a[j];
                if (k < 0 || k%(i-j))
                    continue;
                k/= (i-j);
                cnt[k]--;
            }
        }
        reverse(a, a+n);
    }
    cout << n-res;
}