#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;


int main()
{
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n%3 == 0) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
            int c1 = 1;
            deque<int> d;

            for (int i = 0; i < n; i++) {
                if (c1 == 0)
                    c1 = n;
                d.push_back(c1);
                c1 = (c1+3)%n;
            }
            for (int i = 0; i < n-1; i++) {
                if (d.front() < d.back()) {
                    cout << d.front() << ' ';
                    d.pop_front();
                }
                else {
                    cout << d.back() << ' ';
                    d.pop_back();
                }
            }
            cout << '\n';
        }
    }
}