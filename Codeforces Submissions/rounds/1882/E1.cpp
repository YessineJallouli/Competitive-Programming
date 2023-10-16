#include <bits/stdc++.h>
#define ll long long
using namespace std;

int nb = 0;
int n,m;

vector<int> op1;
vector<int> op2;

vector<int> op(vector<int> &v, int val, int first) {
    vector<int> res;
    int sz = (int) v.size();
    for (int i = 0; i < sz; i++) {
        if (v[i] == val) {
            if (first)
                op1.emplace_back(i+1);
            else
                op2.emplace_back(i+1);
            nb++;
            for (int j = i+1; j < sz; j++)
                res.push_back(v[j]);
            res.push_back(v[i]);
            for (int j = 0; j < i; j++)
                res.push_back(v[j]);
            break;
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            if (a[j] == i) {
                int x = a[i-1];
                a = op(a,x,1);
                a = op(a,i,1);
                a = op(a,x,1);
                break;
            }
        }
    }


    for (int i = 1; i <= m; i++) {
        for (int j = i; j < m; j++) {
            if (b[j] == i) {
                int x = b[i - 1];
                b = op(b, x, 0);
                b = op(b, i, 0);
                b = op(b, x, 0);
                break;
            }
        }
    }

    int nb1 = (int) op1.size();
    int nb2 = (int) op2.size();
    if (nb1%2 != nb2%2 && n%2 == 0 && m%2 == 0) {
        cout << -1 << '\n';
        return 0;
    }

    if (nb1%2 != nb2%2) {
        if (n%2) {
            for (int i = 0; i < n; i++)
                op1.push_back(1);
        }
        else
            for (int i = 0; i < m; i++)
                op2.push_back(1);
    }

    while (op1.size() < op2.size()) {
        op1.push_back(1);
        op1.push_back(n);
    }
    while (op2.size() < op1.size()) {
        op2.push_back(1);
        op2.push_back(m);
    }

    cout << op1.size() << '\n';
    for (int i = 0; i < op1.size(); i++) {
        cout << op1[i] << ' ' << op2[i] << '\n';
    }
    
}