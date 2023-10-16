#include <bits/stdc++.h>
using namespace std;

long long get(deque<int> d, int n, int k) {
    vector<int> ans;
    vector<int> rem;

    for (int i = 0; i < n; i++) {
        if (d.empty())
            break;
        if (d.size() == 1) {
            rem.push_back(d[0]);
            d.pop_back();
            break;
        }
        int a1 = d[0], a2 = d.back();
        if (a1+a2 <= k) {
            ans.push_back(a2);
            ans.push_back(a1);
            d.pop_back();
            d.pop_front();
        }
        else {
            rem.push_back(d.back());
            d.pop_back();
        }
    }
    sort(rem.begin(), rem.end());
    for (int i : rem)
        ans.push_back(i);

//    for (int i : ans) {
//        cout << i << ' ';
//    }
//    cout << "\n";

    long long res = 1+ans[0];
    for (int i = 1; i < n; i++) {
        res+= ans[i];
        if (ans[i]+ans[i-1] > k)
            res++;
    }
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    deque<int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    sort(d.begin(), d.end());
    cout << get(d,n,k);
}