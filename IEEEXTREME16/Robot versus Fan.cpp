//27%
#include<bits/stdc++.h>
#define ll long long
using namespace std;


pair<int,int> dir(char c) {
    if (c == '^')
        return {-1,0};
    if (c == 'v')
        return {1,0};
    if (c == '>')
        return {0,1};
    return {0,-1};
}


int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        char grid[n][n];
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            for (int j = 0; j < n; j++)
                grid[i][j] = s[j];
        }
        vector<pair<int,int>> dust;
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            int a,b; cin >> a >> b;
            dust.emplace_back(a,b);
        }
        pair<int,int> pos = {0,0};
        int timeStamp = 0;
        int limit = 1e8;
        while (timeStamp < limit) {
            if (pos == dust[timeStamp%k])
                break;
            
            auto[X,Y] = pos;
            char c = grid[X][Y];
            auto[x,y] = dir(c);
            int newI = X+x;
            int newJ = Y+y;
            pos = {newI,newJ};
            timeStamp++;
        }
        if (timeStamp != limit)
            cout << timeStamp << '\n';
        else
            cout << "never\n";
    }
}
