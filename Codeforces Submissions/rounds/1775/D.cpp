//
// Created by yessine on 1/10/23.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 6e5+7;
int sieve[N];
int par[N];


vector<set<int>> graph(N);

bool visited[N];
bool searching[N];
map<ll,int> rep;

int Find(int node) {
    if (par[node] == node)
        return node;
    return par[node] = Find(par[node]);
}

void  Union(int n1, int n2) {
    int a1 = Find(n1);
    int a2 = Find(n2);
    if (a1 == a2)
        return;
    par[a1] = a2;
}


set<int> genPrimes(int n) {
    set<int> res;
    while (n != 1) {
        int k = sieve[n];
        res.insert(k);
        n/=k;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    for (int i = 0; i < N; i++)
        par[i] = i;
    memset(sieve, -1, sizeof sieve);
    for (int i = 2; i < N; i++) {
        if (sieve[i] == -1) {
            for (int j = i; j < N; j+= i)
                if (sieve[j] == -1)
                    sieve[j] = i;
        }
    }

    int n; cin >> n;
    int a[n];
    set<int> primeD[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        primeD[i] = genPrimes(a[i]);
        for (int j : primeD[i]) {
            for (int k: primeD[i]) {
                Union(j, k);
                if (j != k) {
                    graph[j].insert(k);
                    rep[j*k] = i+1;
                }
            }
        }
    }

    int s,e; cin >> s >> e;
    s--; e--;
    if (s == e) {
        cout << 1 << '\n';
        cout << s+1;
        return 0;
    }
    for (int i : primeD[e]) {
        searching[i] = true;
    }
    bool ans = false;
    for (int i : primeD[s]) {
        for (int j : primeD[e]) {
            if (Find(i) == Find(j))
                ans = true;
        }
    }
    if (! ans) {
        cout << -1;
        return 0;
    }
    set<int> start;
    for (int i : primeD[s])
        start.insert(i);

    int res = 1;

    map<int,int> prec;

    vector<int> v;

    if (__gcd(a[s], a[e]) != 1) {
        cout << 2 << '\n';
        cout << s+1 << ' ' << e+1 << '\n';
        return 0;
    }

    while (true) {
        res++;
        bool ok = false;
        for (int i : start) {
            if (searching[i]) {
                ok = true;
                int I = i;
                v.push_back(i);
                while (prec.count(I)) {
                    v.push_back(prec[I]);
                    I = prec[I];
                }
                break;
            }
        }
        if (ok)
            break;

        for (int i : start)
            visited[i] = true;
        set<int> nw;
        for (int i : start) {
            for (int g : graph[i]) {
                if (! visited[g] && rep.count(1LL*i*g)) {
                    nw.insert(g);
                    prec[g] = i;
                    visited[g] = true;
                }
            }
        }
        nw.swap(start);
    }

    reverse(v.begin(), v.end());
//    for (int i : v)
//        cout << i << ' ';
//    cout << '\n';

    cout << res << '\n';
    cout << s+1 << ' ';
    for (int i = 0; (int) i < v.size()-1; i++) {
        int k = v[i]*v[i+1];
        int h = rep[k];
        cout << h << ' ';
    }
    cout << e+1;
}