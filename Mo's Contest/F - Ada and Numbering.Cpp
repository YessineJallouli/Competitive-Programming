//https://www.spoj.com/problems/ADANUM/en/
#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

struct query {
    int L,R,id;
    query() {
        L = R = id = 0;
    }
    query(int _L, int _R, int _id) {
        L = _L;
        R = _R;
        id = _id;
    }
};

int block;

bool cmp(query q1, query q2) {
    if (q1.L/block < q2.L/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R < q2.R)
        return true;
    return false;
}

const int N = 2e5+7;
int a[N];
int sum = 0;

ll nb = 0;
int freq[N];
int cntFreq[N];
void del(int val) {
    ll x = cntFreq[freq[val]];
    nb-=freq[val]*x;
    cntFreq[freq[val]]--;
    freq[val]--;
    nb+=freq[val]*x;
}

void ins(int val) {
    ll x = cntFreq[freq[val]+1];
    nb-=freq[val]*(x+1);
    freq[val]++;
    cntFreq[freq[val]]++;
    nb+=freq[val]*(x+1);
}

int main() {
    int n,q; scanf("%d%d", &n,&q);
    block = n/sqrt(q)+1;
    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    unordered_map<int,int> m;
    int K = 0;
    for (int i : s) {
        m[i] = ++K;
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }
    query qr[q];
    for (int i = 0; i < q; i++) {
        int L,R; scanf("%d%d", &L, &R);
        qr[i] = query(L,R,i);
    }
    sort(qr, qr+q, cmp);
    ll ans[q];
    int l = 0, r = -1;
    for (int i = 0; i < q; i++) {
        auto [L,R,id] = qr[i];
        L--; R--;
        while (r < R) {
            r++;
            ins(a[r]);
        }
        while (r > R) {
            del(a[r]);
            r--;
        }
        while (l < L) {
            del(a[l]);
            l++;
        }
        while (l > L) {
            l--;
            ins(a[l]);
        }
        ans[id] = nb;
    }
    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);
}
