#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7;
int tree[N];

int get(int x) {
    int res = 0;
    for (; x; x-= x&(-x))
        res+= tree[x];
    return res;
}

void upd(int x, int val) {
    for (; x < N; x+= x&(-x))
        tree[x]+= val;
}

int getRange(int a, int b) {
    return get(b) - get(a-1);
}


int main(){
    
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i= 1; i <= n; i++) {
        upd(i, 1);
    }
    while (q--) {
        char c; cin >> c;
        if (c == '-') {
            int a; cin >> a;
            upd(a, -1);
        }
        else if (c == '+') {
            int a; cin >> a;
            upd(a,1);
        }
        else {
            bool possible = false;
            int a,b; cin >> a >> b;
            if (a <= b) {
                if (getRange(a, b) == b - a + 1)
                    possible = true;
                if (getRange(1, a) == a && getRange(b, n) == n - b + 1)
                    possible = true;
            }
            else {
                if (getRange(b,a) == a-b+1)
                    possible = true;
                if (getRange(a,n) == n-a+1 && getRange(1,b) == b)
                    possible = true;
            }
            cout << (possible ? "possible\n" : "impossible\n");
        }
    }
}