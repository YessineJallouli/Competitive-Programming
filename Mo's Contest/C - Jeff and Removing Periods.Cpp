//https://codeforces.com/problemset/problem/351/D
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
const int N = 1e5+7;
int a[N];
int cnt[N];
deque<int> lastOcc[N];
bool isPeriodic[N];
set<int> dff[N];
map<int,int> nbD[N];


bool cmp(query q1, query q2) {
    if (q1.L/block < q2.L/block)
        return true;
    if (q1.L/block == q2.L/block && q1.R < q2.R)
        return true;
    return false;
}

int nb = 0;
int periodicNumbers = 0;

void ins(int id, char c) {
    cnt[a[id]]++;
    if (cnt[a[id]] == 1) {
        nb++;
        if (!isPeriodic[a[id]]) {
            periodicNumbers++;
            isPeriodic[a[id]] = true;
        }
    }
    else if (cnt[a[id]] == 2) {
        if (!isPeriodic[a[id]]) {
            periodicNumbers++;
            isPeriodic[a[id]] = true;
        }
    }
    if (c == 'R') {
        if (lastOcc[a[id]].size() != 0) {
            int df = abs(lastOcc[a[id]].back() - id);
            nbD[a[id]][df]++;
            if (nbD[a[id]][df] == 1)
               dff[a[id]].insert(df);
        }
        lastOcc[a[id]].push_back(id);
    }
    else {
        if (lastOcc[a[id]].size() != 0) {
            int df = abs(lastOcc[a[id]][0]-id);
            nbD[a[id]][df]++;
            if (nbD[a[id]][df] == 1)
                dff[a[id]].insert(df);
        }
        lastOcc[a[id]].push_front(id);
    }
    if (cnt[a[id]] > 2) {
        if (c == 'R') {
            if (*dff[a[id]].begin() != *dff[a[id]].rbegin() && isPeriodic[a[id]]) {
                periodicNumbers--;
                isPeriodic[a[id]] = false;
            }
        }
        else {
            if (*dff[a[id]].begin() != *dff[a[id]].rbegin() && isPeriodic[a[id]]) {
                isPeriodic[a[id]] = false;
                periodicNumbers--;
            }
        }
    }
}

void del(int id, char c) {
    cnt[a[id]]--;
    if (cnt[a[id]] == 0) {
        if (isPeriodic[a[id]]) {
            isPeriodic[a[id]] = false;
            periodicNumbers--;
        }
        nb--;
    }
    else if (cnt[a[id]] == 1) {
        if (!isPeriodic[a[id]]) {
            isPeriodic[a[id]] = true;
            periodicNumbers++;
        }
    }
    else if (cnt[a[id]] == 2) {
        if (! isPeriodic[a[id]]) {
            isPeriodic[a[id]] = true;
            periodicNumbers++;
        }
    }
    if (c == 'R') {
        if (lastOcc[a[id]].size() > 1) {
            int sz = lastOcc[a[id]].size();
            int df = abs(lastOcc[a[id]][sz-1] - lastOcc[a[id]][sz-2]);
            nbD[a[id]][df]--;
            if (nbD[a[id]][df] == 0)
               dff[a[id]].erase(df);
        }
        lastOcc[a[id]].pop_back();
    }
    else {
        if (lastOcc[a[id]].size() > 1) {
            int df = abs(lastOcc[a[id]][0]-lastOcc[a[id]][1]);
            nbD[a[id]][df]--;
            if (nbD[a[id]][df] == 0)
               dff[a[id]].erase(df);
        }
        lastOcc[a[id]].pop_front();
    }
    if (cnt[a[id]] > 2) {
        if (! isPeriodic[a[id]]) {
            if (*dff[a[id]].begin() == *dff[a[id]].rbegin()) {
                isPeriodic[a[id]] = true;
                periodicNumbers++;
            }
        }
    }
}

int main() {
    //SaveTime
    int n; cin >> n;
    block = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q; cin >> q;
    query qr[q];
    for (int i = 0; i < q; i++) {
        int L,R; cin >> L >> R;
        qr[i] = query(L,R,i);
    }
    sort(qr, qr+q, cmp);
    int l = 0, r = -1;
    memset(cnt, 0, sizeof cnt);
    int ans[q];
    for (int i = 0; i < q; i++) {
        int L = qr[i].L, R = qr[i].R, id = qr[i].id;
        L--; R--;
        while (r < R) {
            r++;
            ins(r, 'R');
        }
        while (r > R) {
            del(r, 'R');
            r--;
        }
        while (l < L) {
            del(l, 'L');
            l++;
        }
        while (l > L) {
            l--;
            ins(l, 'L');
        }
        ans[id] = nb;
        if (periodicNumbers == 0)
            ans[id]++;
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << '\n';
}
