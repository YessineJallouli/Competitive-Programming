#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string a[N],s[N];

/*struct node {
    map<char, node*> edges;
    int end;
    node() {
        this->edges = map<char,node*>();
        this->end = 0;
    }
};

void insert(string &s, node *n, int l = 0) {
    if (l == s.length())
        n->end++;
    else {
        if (n->edges.count(s[l]) == 0) {
            node* p = new node;
            n->edges[s[l]] = p;
        }
        insert(s, n->edges[s[l]], l+1);
    }
}*/

int main() {
    int t;
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> a[i];
            s[i]=a[i];
        }
        sort(s,s+n);
        for(int i=0;i<n;++i){
            string pref="";
            int ans=a[i].length()+1;
            int d= lower_bound(s,s+n,a[i])-s+1;
            int u=n-d+2;
            ans=min(ans, min(d,u));
//            cout << ans << '-';
            int prevlow = 0;
            for(int j=0;j<a[i].length() && j < 10000;++j){
                pref+=a[i][j];
                int low= lower_bound(s+prevlow,s+n,pref)-s+1;
                prevlow = low;
                int order=d-low+1;
                int up= upper_bound(s+prevlow,s+n,pref+'{')-s+1;
                int nb=up-low;
//                cout << pref << ' ' << nb << '\n';
                int rev_order=nb-order+2;
                //cout << order << ' ' << rev_order << '\n';
                ans=min(ans,j+1+min(order,rev_order));
            }
            cout << ans << ' ';
        }
        cout << '\n';

    }
}