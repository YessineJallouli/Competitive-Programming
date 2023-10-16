#include <bits/stdc++.h>
using namespace std;


const int N = 2e5+2;

vector<vector<int>> implication_graph(N);
vector<vector<int>> inv_graph(N);

bool marked[N];

bool visited[N];


deque<int> p;
deque<int> component;

int cmp[N];


void dfs(int node) {
    if (marked[node])
        return;
    marked[node] = true;
    for (int v : implication_graph[node])
        dfs(v);
    p.push_front(node);
}

void dfs1(int node, int nb) {
    if (marked[node])
        return;
    marked[node] = true;
    for (int v : inv_graph[node])
        dfs1(v, nb);
    component.push_front(node);
}

void dfs2(int node) {
    if (visited[node])
        return;
    visited[node] = true;
    for (int v : implication_graph[node])
        dfs2(v);
}




int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int n; cin >> n;

    int bet[n][7];

    int d[7];

    for (int i = 0; i < 7; i++)
        cin >> d[i];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> bet[i][j];
        }
    }

    int sh[7];
    memset(sh, 0, sizeof sh);
    for (int i = 1; i < 7; i++) {
        sh[i] = sh[i-1] + d[i-1];
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 7; j++) {
//            cout << abs(bet[i][j]) + sh[j] << ' ';
//        }
//        cout << '\n';
//    }
//
//    cout << '\n';


    for (int ps = 0; ps < n; ps++) {
        for (int i = 0; i < 7; i++) {
            for (int j = i+1; j < 7; j++) {

                int node1 = 2*(abs(bet[ps][i]) + sh[i]-1);
                int node2 = 2*(abs(bet[ps][j]) + sh[j]-1);



                if (bet[ps][i] < 0) {
                    node1++;
                }
                if (bet[ps][j] > 0) {
                    node2++;
                }

                implication_graph[node1].push_back(node2);
                inv_graph[node2].push_back(node1);

                implication_graph[node2^1].push_back(node1^1);
                inv_graph[node1^1].push_back(node2^1);

            }
        }
    }



    for (int i = 0; i < N; i++) {
        if (implication_graph[i].empty() && inv_graph[i].empty())
            continue;
        dfs(i);
    }

    for (int i = 0; i < N; i++)
        marked[i] = false;


    int scc = 1;

    for (int i = 0; i < p.size(); i++) {
        if (marked[p[i]])
            continue;
        component.clear();
        dfs1(p[i], scc);
        for (int j : component)
            cmp[j] = scc;
//        cout << "Component number " << scc << '\n';
//        for (int j : component)
//            cout << j << ' ';
//        cout << '\n';
        scc++;
    }

    bool ans = true;

    for (int i = 0; i < N; i+= 2) {
        if (cmp[i] == cmp[i+1] && cmp[i])
            ans = false;
    }

    int p6,p7; cin >> p6 >> p7;

    int node6 = 2*(abs(p6) + sh[5]-1);
    int node7 = 2*(abs(p7) + sh[6]-1);

    if (p6 < 0)
        node6++;
    if (p7 < 0)
        node7++;

    dfs2(node6);
    dfs2(node7);

    for (int i = 0; i < N; i+= 2) {
        if (visited[i] && visited[i+1]) {
            ans = false;
        }
    }


    if (ans)
        cout << "possible";
    else
        cout << "impossible";
}