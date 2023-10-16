#include <bits/stdc++.h>
using namespace std;

int m;


int getL(int id) {
    string s = "";
    for (int i = 0; i < m; i++) {
        s+= '0';
    }
    s[id] = '1';
    cout << "? " << s << endl;
    int x; cin >> x;
    return x;
}

int query(string &s) {
    cout << "? " << s << endl;
    int x; cin >> x;
    return x;
}

int main()
{
    int n; cin >> n >> m;
    vector<pair<int,int>> len(m);
    for (int i = 0; i < m; i++) {
        len[i] = {getL(i), i};
    }
    sort(len.begin(), len.end());
    int s = 0;
    string q = "";
    for (int i = 0; i < m; i++)
        q+= '0';
    for (int i = 0; i < m; i++) {
        int id = len[i].second;
        q[id] = '1';
        int x = query(q);
        if (s+len[i].first != x) {
            q[id] = '0';
        }
        else {
            s = x;
        }
    }
    cout << "! " << s << endl;
}