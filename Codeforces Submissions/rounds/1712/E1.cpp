#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+1;
vector<int> dv[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for (int i = 1; i < N; i++)
        dv[i].push_back(1);

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j+= i)
            dv[j].push_back(i);
    }

    int T; cin >> T;
    while (T--) {
        int l,r; cin >> l >> r;
        ll nb = 0;


        for (int k = l; k <= r; k++) {
            int x = 2*k;

            vector<int> div;
            for (int i : dv[x]) {
                if (i >= l && i < k) {
                    div.push_back(i);
                }
            }

            int cnt = 0;
            for (int i = 0; i < div.size(); i++) {
                for (int j = i+1; j < div.size(); j++) {
                    int I = div[i], J = div[j], K = k;
                    if ((k%I != 0 || K%J != 0) && 2*K < I+J+K) {
                        cnt++;
                    }
                }
            }
            nb+= cnt;
        }
        for (int k = l; k <= r; k++) {
            int cnt = 0;
            for (int i : dv[k]) {
                if (i >= l && i != k) {
                    cnt++;
                }
            }
            nb+= cnt*(cnt-1)/2;
        }
        ll k = r-l+1;
        cout << k*(k-1)*(k-2)/6-nb << '\n';
    }
}