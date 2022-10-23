// 100%
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {
            int ord = (c-'a'+14)%26;
            c = ord+'a';
        }
        if (c >= 'A' && c <= 'Z') {
            int ord = (c-'A'+14)%26;
            c = ord+'A';
        }
        cout << c;
    }
}
