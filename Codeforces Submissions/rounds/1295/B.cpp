#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,x; cin >> n >> x;
        string s; cin >> s;
        int balance = 0;
        map<int,int> nbseen;
        set<int> pr;
        pr.insert(0);
        for (char c : s) {
            nbseen[balance]++;
            pr.insert(balance);
            if (c == '0')
                balance++;
            else
                balance--;
        }
        if (balance == 0 && nbseen.count(x))
            cout << -1 << '\n';
        else if (balance == 0 && !nbseen.count(x))
            cout << 0 << '\n';
        else {
            int ans = 0;
            for (int i : pr)
                if ((x-i)%balance == 0 && 1LL*(x-i)*balance >= 0)
                    ans+= nbseen[i];
            cout << ans << '\n';
        }
    }
}