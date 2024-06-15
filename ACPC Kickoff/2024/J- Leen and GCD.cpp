#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
vector<int> v;
bool ans;
int p10[1000];
map<tuple<int,int,int>, bool> mp;
vector<int> answer;

bool solve(int k, int pos, int mod = 0) {
    if (pos*9+10 < k)
        return false;
    if (mp.count({k, pos, mod}))
        return mp[{k, pos, mod}];
    if (k == 0 && pos == -1) {
        if (mod == 0) {
            ans = true;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] != 0) {
                    for (int j = i; j < v.size(); j++) {
                        answer.push_back(v[j]);
                    }
                    break;
                }
            }
            return mp[{k, pos, mod}] = true;
        }
        return mp[{k, pos, mod}] = false;
    }
    bool res = false;
    for (int digit = 0; digit <= 9 && ! ans; digit++) {
        if (digit > k)
            continue;
        v.push_back(digit);
        res = res | solve(k-digit, pos-1, (mod + digit*p10[pos])%n);
        v.pop_back();
    }
    return mp[{k, pos, mod}] = res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    ans = false;
    p10[0] = 1;
    for (int i = 1; i < 1000; i++) {
        p10[i] = (p10[i-1]*10)%n;
    }
    solve(n, n/9+4);
    for (int i : answer) {
        cout << i;
    }
}
