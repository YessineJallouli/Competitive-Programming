//78%
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int delta[4][2] = {{1,0}, {0,-1}, {0,1}, {-1, 0}};


char dir(int t) {
    if (t == 0)
        return 'D';
    else if (t == 1)
        return 'L';
    else if (t == 2)
        return 'R';
    return 'U';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int n,m; cin >> n >> m;
        int grid[n][m];
        int visitedByGost[n][m];
        memset(visitedByGost, false, sizeof visitedByGost);
        set<tuple<string,int,int>> pacMan;
        vector<pair<int,int>> ghosts;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            for (int j = 0; j < m; j++) {
                grid[i][j] = s[j];
                if (grid[i][j] == 'P')
                    pacMan.insert({"", i,j});
                if (grid[i][j] == 'G')
                    ghosts.emplace_back(i,j);
            }
        }
        int distance = 0;
        bool inf = false;
        pair<int,int> minTarget = {n,m};
        map<pair<int,int>, string> shortestPath;
        while (! pacMan.empty()) {

            for (auto [i,j] : ghosts) {
                visitedByGost[i][j] = true;
            }
            vector<pair<int,int>> auxGhost;
            for (auto [i,j] : ghosts) {
                for (int t = 0; t < 4; t++) {
                    int newI = i+delta[t][0];
                    int newJ = j+delta[t][1];
                    if (newI >= 0 && newJ >= 0 && newI < n && newJ < m) {
                        if (visitedByGost[newI][newJ])
                            continue;
                        if (grid[newI][newJ] == 'X')
                            continue;
                        auxGhost.emplace_back(newI, newJ);
                        visitedByGost[newI][newJ] = true;
                    }
                }
            }
            set<tuple<string,int,int>> auxPac;
            map<pair<int,int>, bool> mp;
            for (auto [s, i,j] : pacMan) {
                if (! shortestPath.count({i,j})) {
                    shortestPath[{i,j}] = "";
                    mp[{i,j}] = true;
                }
                if (! visitedByGost[i][j]) {
                    auxPac.insert({shortestPath[{i,j}], i, j});
                }
                for (int t = 0; t < 4; t++) {
                    int newI = i+delta[t][0];
                    int newJ = j+delta[t][1];
                    if (newI >= 0 && newJ >= 0 && newI < n && newJ < m) {
                        if (visitedByGost[newI][newJ])
                            continue;
                        if (grid[newI][newJ] == 'X')
                            continue;
                        if (mp.count({newI, newJ}))
                            continue;
                        mp[{newI, newJ}] = true;
                        if (! shortestPath.count({newI, newJ})) {
                            shortestPath[{newI, newJ}] = shortestPath[{i,j}] + dir(t);
                        }
                        auxPac.insert({shortestPath[{newI,newJ}], newI, newJ});
                    }
                }
            }
            if (auxPac == pacMan && auxGhost == ghosts) {
                inf = true;
                for (auto [s, i,j] : pacMan) {
                    minTarget = min(minTarget, {i,j});
                }
                if (shortestPath[minTarget] == "") {
                    shortestPath[minTarget] = "STAY";
                }
                cout << "Case #" << tt << ": " <<  "INFINITE " << shortestPath[minTarget] << '\n';
                break;
            }
            auxGhost.swap(ghosts);
            auxPac.swap(pacMan);
            if (pacMan.empty()) {
                for (auto [s,i,j] : auxPac) {
                    minTarget = min(minTarget, {i,j});
                }
                break;
            }
            distance++;
        }
        if (inf)
            continue;
        if (shortestPath[minTarget] == "") {
            shortestPath[minTarget] = "STAY";
        }
        cout << "Case #" << tt << ": " << distance << ' ' << shortestPath[minTarget] << '\n';
    }
}
