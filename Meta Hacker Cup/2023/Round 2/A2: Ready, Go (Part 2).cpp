#include <bits/stdc++.h>
#define ll long long
#define SaveTime ios_base::sync_with_stdio(false), cin.tie(0);
using namespace std;

/// Global variables

static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
            "mov %%rsp, (%0)\n"
            "mov %0, %%rsp\n"
            :
            : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

const int N = 3001;
char g[N][N];
bool visited[N][N];
int n,m;

int delta[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

vector<pair<int,int>> component;

void dfs(int x, int y) {
    if (visited[x][y])
        return;
    visited[x][y] = true;
    component.emplace_back(x,y);
    for (int t = 0; t < 4; t++) {
        int newX = x+delta[t][0];
        int newY = y+delta[t][1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < m && g[newX][newY] == 'W') {
            dfs(newX, newY);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = s[j];
            visited[i][j] = false;
        }
    }
    int res = 0;
    map<pair<int,int>,int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W' && !visited[i][j]) {
                component.clear();
                dfs(i,j);
                set<pair<int,int>> s;
                for (auto [x,y] : component) {
                    for (int t = 0; t < 4; t++) {
                        int newX = x+delta[t][0];
                        int newY = y+delta[t][1];
                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && g[newX][newY] == '.') {
                            s.insert({newX, newY});
                        }
                    }
                }
                if (s.size() == 1) {
                    mp[*s.begin()]+= (int) component.size();
                    res = max(res, mp[*s.begin()]);
                }
            }
        }
    }
    cout << res << '\n';
}

int main() {
    SaveTime
    freopen("ready_go_part_2_input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ll T; cin >> T;
    for (ll ii = 1; ii <= T; ii++) {
        cout << "Case " << "#" << ii << ": ";
        run_with_stack_size(solve, 1024 * 1024 * 1024);
    }
}