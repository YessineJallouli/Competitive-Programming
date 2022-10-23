//100%
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll,string>
using namespace std;

const int mx = 5e5+7;

int par[mx];

int Find(int node) {
    if (par[node] == node)
        return node;
    return par[node] = Find(par[node]);
}

void  Union(int n1, int n2) {
    int a1 = Find(n1);
    int a2 = Find(n2);
    if (a1 == a2)
        return;
    par[a1] = a2;
}

pair<int,int> dir(char c) {
    if (c == 'S')
        return {1,0};
    if (c == 'N')
        return {-1,0};
    if (c == 'E')
        return {0,1};
    return {0,-1};
}


int main() {

    for (int i = 0; i < mx; i++)
        par[i] = i;

    int n,w; cin >> n >> w;

    int nodeMonster = n-1;
    int escape = n*(n-1) + n-1;
    int myNode = 0;

    while (w--) {
        int i,j; char c;
        cin >> i >> j >> c;
        auto[x,y] = dir(c);
        int newI = i+x;
        int newJ = j+y;
        char ans = 'K';
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < n) {
            int node1 = n*i+j;
            int node2 = n*newI+newJ;
            if (Find(node1) == Find(myNode) && Find(nodeMonster) == Find(node2))
                ans = 'M';
            else if (Find(node2) == Find(myNode) && Find(nodeMonster) == Find(node1))
                ans = 'M';
            else {
                if (Find(node1) == Find(node2) && Find(myNode) == Find(node1))
                    ans = 'L';
                else {
                    Union(node1, node2);
                    if (Find(myNode) == Find(escape))
                        ans = 'T';
                }
            }
        }
        cout << ans << '\n';
    }
}
