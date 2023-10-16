#include <bits/stdc++.h>
# define repeat(n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
    string s; cin >> s;
    int sum = 0;
    int nbC = 0;
    int n = s.length();
    repeat(n) {
        if (s[i] == ')')
            sum--;
        else
            sum++;
        if (sum < 0)
            sum = 0;
        else if (s[i] == ')')
            nbC++;
    }
    cout << nbC*2;
}