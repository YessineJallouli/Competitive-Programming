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
        int n; cin >> n;
        vector<int> v(n);
        cin >> v;
        int d = -1;
        int f = -1;
        for (int i = n-2; i >= 0; i--) {
            if (v[i] == v[i+1])
                d = i;
        }
        for (int i = 0; i < n-1; i++) {
            if (v[i] == v[i+1])
                f = i+1;
        }
        if (d == -1 || f <= d+1) {
            cout << 0 << '\n';
        }
        else {
            d++; f--;
            cout << max(1,f-d) << '\n';
        }
    }
}