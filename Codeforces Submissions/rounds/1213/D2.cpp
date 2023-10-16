#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
vector<int> cnt[N];

int main() {
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int x = a[i];
        int nbOperations = 0;
        while (x) {
            cnt[x].push_back(nbOperations);
            nbOperations++;
            x/= 2;
        }
    }
    int ans = INT_MAX;
    for (int x = 0; x < N; x++) {
        if (cnt[x].size() < k)
            continue;
        sort(cnt[x].begin(), cnt[x].end());
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum+= cnt[x][i];
        }
        ans = min(ans, sum);
    }
    cout << ans;
}