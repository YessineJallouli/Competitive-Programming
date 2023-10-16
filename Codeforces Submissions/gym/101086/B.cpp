//
// Created by yessine on 11/17/22.
//

#include <bits/stdc++.h>
using namespace std;

int orderLeaf = 1;
const int N = 1e5+7;

vector<int> leaf;
int depth[N];

struct expression {
    double h, r,x0;
};

expression nodeExpression[N];

void dfs(int node, vector<vector<int>> &tree, int d = 0) {
    depth[node] = d;
    if (tree[node].empty())
        leaf.push_back(node);
    for (int ch : tree[node]) {
        dfs(ch, tree, d+1);
    }
}

expression getExpression(int node, vector<vector<int>> &tree) {
    if (tree[node].empty()) {
        return nodeExpression[node];
    }

    expression expression1 = getExpression(tree[node][0], tree);
    expression expression2 = getExpression(tree[node][1], tree);

    expression result;
    result.r = (expression1.r + expression2.r)/2.0;
    result.h = (expression1.h + expression2.h)/2.0;
    result.x0 = (expression1.x0 + expression2.x0)/2.0;

    return nodeExpression[node] = result;
}



int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int n,q; cin >> n >> q;
        vector<vector<int>>  tree(n+1);
        set<int> rt;
        for (int i = 1; i <= n; i++)
            rt.insert(i);

        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            if (k != 0) {
                int a,b; cin >> a >> b;
                tree[i].push_back(a);
                tree[i].push_back(b);
                rt.erase(a);
                rt.erase(b);
            }
        }

        int root = *rt.begin();
        orderLeaf = 1;
        leaf.clear();
        dfs(root, tree);

        for (int i = 0; i < leaf.size(); i++) {
            nodeExpression[leaf[i]].h = i;
            nodeExpression[leaf[i]].r = 2*i;
            nodeExpression[leaf[i]].x0 = 1;
        }

        getExpression(root, tree);



        expression x0;

        x0.x0 = 0;
        x0.h = -nodeExpression[root].h/nodeExpression[root].x0;
        x0.r = -nodeExpression[root].r/nodeExpression[root].x0;

        for (int i = 1; i <= n; i++) {
            nodeExpression[i].x0 = 0;
            nodeExpression[i].h+= x0.h;
            nodeExpression[i].r+= x0.r;
        }
        cout.precision(4);
        while (q--) {
            int r,V,H;
            int U;
            cin >> r >> V >> H >> U;
            cout << fixed << r*nodeExpression[U].r + H*nodeExpression[U].h << ' ' << fixed << -(V+2*r)*depth[U] << '\n';
        }
    }
}