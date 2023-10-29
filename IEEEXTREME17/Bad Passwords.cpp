//100%
#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

bool match(vector<int>& v1, vector<int>& v2){
    for(int x:v1){
        for(int y:v2){
            if(x==y) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n;
    vector<vector<string> > seq(n);
    map<string,vector<int> > wordset;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        while(x--){
            string s;
            cin >> s;
            seq[i].push_back(s);
            wordset[s].push_back(i);
        }
    }
    cin >> m;
    for(int i=0;i<m;++i) {
        string p1, p2;
        cin >> p1 >> p2;
        int l = 0, r = 0, len1 = p1.length(), len2 = p2.length();
        for (int j = 0; j < min(len1, len2); ++j) {
            if (p1[j] == p2[j]) l++; else break;
        }
        for (int j = 0; j < min(len1, len2); ++j) {
            if (p1[len1 - 1 - j] == p2[len2 - 1 - j]) r++; else break;
        }

        bool search = true;
        for (int d1 = 0; d1 <= l && search; ++d1) {
            for (int d2 = 0; d2 <= r && search; ++d2) {
                string m1 = p1.substr(d1, len1 - d1 - d2);
                string m2 = p2.substr(d1, len2 - d1 - d2);
                //cout << m1 << ' ' << m2 << '\n';
                if (!wordset.count(m1) || !wordset.count(m2)) {
                    continue;
                } else {
                    if (match(wordset[m1],wordset[m2])) {
                        cout << "REJECT\n";
                        search = false;
                    }
                }
            }
        }
        if (search) cout << "OK\n";
    }
}
