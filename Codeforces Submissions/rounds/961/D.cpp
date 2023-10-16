#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool colinear(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3) {
    auto [x1,y1] = p1;
    auto [x2,y2] = p2;
    auto [x3,y3] = p3;
    return (1LL*(x1-x2)*(y2-y3) == 1LL*(x2-x3)*(y1-y2));
}

const int N = 1e5+7;
pair<int,int> points[N];
int n;

bool can(pair<int,int> p1, pair<int,int> p2) {
    vector<pair<int,int>> nonColinear;
    for (int i = 0; i < n; i++) {
        if (! colinear(p1,p2,points[i])) {
            nonColinear.emplace_back(points[i]);
        }
    }
    if (nonColinear.size() < 2)
        return true;
    for (int i = 0; i < (int) nonColinear.size(); i++) {
        if (!colinear(nonColinear[0], nonColinear[1], nonColinear[i]))
            return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    if (n < 5) {
        cout << "YES\n";
        return 0;
    }
    if (can(points[0], points[1]) || can(points[0], points[2]) || can(points[1], points[2]))
        cout << "YES\n";
    else
        cout << "NO\n";

}