#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    //ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        string a,b; cin >> a >> b;
        bool op = true;
        while (op) {
            bool d = false;
            string s1 = "";
            string s2 = "";
            int n1 = a.size();
            int n2 = b.size();
            for (int i = 0; i < n1; i++) {
                if (i < n1-1 && a[i] == a[i+1]) {
                    d = true;
                    i++;
                    continue;
                }
                if (i < n1-2 && a[i] == a[i+2]) {
                    if (a[i] == 'A' && a[i+1] == 'C') {
                        s1+= a[i];
                        continue;
                    }
                    if (a[i] == 'C'&& a[i+1] == 'A') {
                        s1+= a[i];
                        continue;
                    }
                    d = true;
                    s1+= a[i+1];
                    i+=2;
                    continue;
                }
                s1+= a[i];
            }
            for (int i = 0; i < n2; i++) {
                if (i != n2-1 && b[i] == b[i+1]) {
                    d = true;
                    i++;
                    continue;
                }
                if (i < n2-2 && b[i] == b[i+2]) {
                    if (b[i] == 'A' && b[i+1] == 'C') {
                        s2+= b[i];
                        continue;
                    }
                    if (b[i] == 'C'&& b[i+1] == 'A') {
                        s2+= b[i];
                        continue;
                    }
                    d = true;
                    s2+= b[i+1];
                    i+=2;
                    continue;
                }
                s2+= b[i];
            }
            a = s1; b = s2;
            if (! d)
                break;
        }
        string s1 = "";
        string s2 = "";
        int nb1 = 0;
        int nb2 = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != 'B')
                s1+= a[i];
            else
                nb1++;
        }
        for (int i = 0; i < b.size(); i++) {
            if (b[i] != 'B')
                s2+= b[i];
            else
                nb2++;
        }
        //cout << s1 << ' ' << s2 << endl;
        if (s2 == s1 && (nb1+nb2)%2 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }

    }
}