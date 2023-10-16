#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string a[n], b[n];
        map<string, int> nbA;
        map<string, int> nbB;
        set<string> s1;
        set<string> s2;
        int nbO = 0;
        int cnt1[10];
        int cnt2[10];
        memset(cnt1, 0, sizeof cnt1);
        memset(cnt2, 0, sizeof cnt2);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == "1")
                nbO++;
            s1.insert(a[i]);
            nbA[a[i]]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] == "1")
                nbO--;
            s2.insert(b[i]);
            nbB[b[i]]++;
        }
        for (string ch : s1) {
            int k = min(nbA[ch], nbB[ch]);
            nbA[ch]-= k;
            nbB[ch]-= k;
        }
        int ans = 0;
        for (string ch : s1) {
            string t = to_string((int) ch.size());
            int k = min(nbB[t], nbA[ch]);
            if (t == "1")
                continue;
            nbA[ch]-= k;
            nbB[t]-= k;
            
            ans+= k;
        }
        for (string ch : s2) {
            string t = to_string((int) ch.size());
            int k = min(nbA[t], nbB[ch]);
            if (t == "1")
                continue;
            nbB[ch]-= k;
            nbA[t]-= k;
            ans+= k;
        }
        for (string ch : s1) {
            cnt1[(int) ch.size()]+= nbA[ch];
        }
        for (string ch : s2) {
            cnt2[(int) ch.size()]+= nbB[ch];
        }
        for (int i = 0; i < 10; i++) {
            int k = min(cnt1[i], cnt2[i]);
            cnt1[i]-= k;
            cnt2[i]-= k;
            ans+= 2*k;
            ans+= max(cnt1[i], cnt2[i]);
            if (i != 1)
                ans+= max(cnt1[i], cnt2[i]);
        }
        cout << ans-abs(nbO) << '\n';
    }
}