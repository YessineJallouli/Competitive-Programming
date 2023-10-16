#include <bits/stdc++.h>
using namespace std;

const int N = 500;
char grid[N][N];
int r,c;

map<char, pair<int,int>> dir;

tuple<int,int,char> rotate(tuple<int,int,char> t) {
    char direction = get<2>(t);
    if (direction == 'U')
        direction = 'R';
    else if (direction == 'R')
        direction = 'D';
    else if (direction == 'D')
        direction = 'L';
    else
        direction = 'U';
    get<2>(t) = direction;
    return t;
}

tuple<int,int,char> next(tuple<int,int,char> position) {
    while (true) {
        char D = get<2>(position);
        pair<int,int> direction = dir[D];
        int nextY = direction.first+get<0>(position);
        int nextX = direction.second+get<1>(position);
        if (grid[nextY][nextX] == '.') {
            return {nextY, nextX,D};
        }
        position = rotate(position);
    }
}


int main() {
    freopen("reduce.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    dir['U'] = {-1,0};
    dir['R'] = {0,1};
    dir['D'] = {1,0};
    dir['L'] = {0,-1};

    int T; cin >> T;
    while (T--) {
        int q; cin >> r >> c >> q;
        tuple<int,int,char> L;
        cin >> get<0>(L) >> get<1>(L) >> get<2>(L);
        get<0>(L)--; get<1>(L)--;

        tuple<int,int,char> initial_state = L;
        for (int i = 0; i < r; i++) {
            string s; cin >> s;
            for (int j = 0; j < c; j++) {
                grid[i][j] = s[j];
            }
        }

        auto [a,b,_0]=L;
        if(grid[a+1][b]=='#' && grid[a-1][b]=='#' && grid[a][b+1]=='#' && grid[a][b-1]=='#')
        {
            cout << 0 << '\n';
            continue;
        }

        vector<pair<int,int>> pos;
        pos.emplace_back(get<0>(L), get<1>(L));
        while (q--) {
            char o; cin >> o;
            if (o == 'R') {
                L = rotate(L);
            }
            else {
                int nb; cin >> nb;
                while (nb--) {
                    L = next(L);
                    pos.emplace_back(get<0>(L), get<1>(L));
                }
            }
        }
        int id = 0;
        int ans = 0;
        L = initial_state;

        while (id < pos.size()-1) {

            while (get<0>(next(L)) != pos[id+1].first || get<1>(next(L)) != pos[id+1].second) {
                L = rotate(L);
                ans++;
            }

            bool b = false;
            while (id != pos.size()-1 && get<0>(next(L)) == pos[id+1].first && get<1>(next(L)) == pos[id+1].second) {
                id++;
                L = next(L);
                b = true;
            }
            if (b)
                ans++;
        }
        cout << ans << '\n';
    }
}