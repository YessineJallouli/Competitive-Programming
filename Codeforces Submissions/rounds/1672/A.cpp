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
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        cin >> v;
        int nb = 0;
        int sum = 0;
        for (int i = 0; i <n; i++) {
            if (v[i] == 1)
                nb++;
            else
                sum+= v[i]-1;
        }
        if (nb == n) {
            cout << "maomao90\n";
        }
        else if (sum%2 == 0) {
            cout << "maomao90\n";
        }
        else {
            cout << "errorgorn\n";
        }
    }
}