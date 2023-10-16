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

bool can(pair<int,int> p1, pair<int,int> p2, const vector<pair<int,int>> &twoLines) {
    vector<pair<int,int>> nonColinear;
    for (int i = 0; i < twoLines.size(); i++) {
        if (! colinear(p1,p2,twoLines[i])) {
            nonColinear.emplace_back(twoLines[i]);
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
    if (n < 7) {
        cout << "possible";
        return 0;
    }

    bool ans = false;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            pair<int,int> p1 = points[i];
            pair<int,int> p2 = points[j];
            bool ok[n];
            memset(ok, false, sizeof ok);
            vector<pair<int,int>> otherTwo;
            for (int k = 0; k < n; k++) {
                if (colinear(p1, p2, points[k]))
                    ok[k] = true;
                else {
                    otherTwo.push_back(points[k]);
                }
            }
            if (otherTwo.size() < 5)
                ans = true;
            else {
                if (can(otherTwo[0], otherTwo[1], otherTwo) || can(otherTwo[0], otherTwo[2], otherTwo) || can(otherTwo[1], otherTwo[2], otherTwo))
                    ans = true;
            }
        }
    }
    if (ans) {
        cout << "possible";
    }
    else {
        cout << "impossible";
    }
}