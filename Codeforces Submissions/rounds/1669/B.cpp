#include <bits/stdc++.h>
#define ll lo
using namespace std;
int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int,int> cnt;
        int id = -1;
        for (int i = 0; i <n; i++) {
            int x; cin >> x;
            cnt[x]++;
            if (cnt[x] >= 3)
                id = x;
        }
        cout << id << endl;
    }
}