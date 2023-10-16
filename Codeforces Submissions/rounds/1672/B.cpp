#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
std::istream& operator>>(std::istream &H,std::vector<T>&a)
{
    for(auto &i:a)
        H>>i;
    return H;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        bool ans = true;
        int nb = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'B')
                nb--;
            else
                nb++;
            if (nb < 0)
                ans = false;
        }
        if (s[0] == 'B' || s.back() == 'A')
            ans = false;
        cout << (ans ? "YES\n" : "NO\n");
    }
}