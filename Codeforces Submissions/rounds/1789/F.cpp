#include <bits/stdc++.h>
using namespace std;

string s;
int ans = 0;

int LCS_two(deque<char> &a, deque<char> &b) {
    int n = (int) a.size(), m = (int) b.size();
    int dp[n+1][m+1];
    memset(dp, 0, sizeof dp);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
                dp[i+1][j+1] = dp[i][j]+1;
            else
                dp[i+1][j+1] = max (dp[i][j+1],dp[i+1][j]);
            res = max(res, dp[i+1][j+1]);
        }
    }
    return res;
}

int LCS_three(deque<char> &s1, deque<char> &s2, deque<char> &s3) {
    int n = (int) s1.size(), m = (int) s2.size(), o = (int) s3.size();
    int dp[n+1][m+1][o+1];
    for (int i=0; i <= n; i++) {
        for (int j=0; j <= m; j++) {
            for (int k=0; k <= o; k++) {
                if (i==0 || j==0 || k==0)
                    dp[i][j][k] = 0;
                else if (s1[i-1] == s2[j-1] && s1[i-1]==s3[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k],dp[i][j][k-1]});
            }
        }
    }
    return dp[n][m][o];
}

int get(string pattern) {
    int n = (int) pattern.size();
    if (n == 0)
        return 0;
    int id = 0;
    for (char i : s) {
        if (i == pattern[id%n]) {
            id++;
        }
    }
    id = id - id%n;
    if (id > n)
        return id;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = (int) s.size();
    deque<char> part1,part2,part3;
    for (int i = 0; i < n; i++)
        part2.push_back(s[i]);

    for (int i = 1; i < n; i++) {
        // part1 [0..i-1] part2 [i..n-1]
        part2.pop_front();
        part1.push_back(s[i-1]);
        ans = max(ans, LCS_two(part1, part2)*2);
    }

    part1.clear(); part2.clear();
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            // part1 [0..i-1] part2 [i..j] part3[j+1..n-1]
            part1.clear(); part2.clear(); part3.clear();
            for (int k = 0; k < i; k++)
                part1.push_back(s[k]);
            for (int k = i; k <= j; k++)
                part2.push_back(s[k]);
            for (int k = j+1; k < n; k++)
                part3.push_back(s[k]);
            ans = max(ans, LCS_three(part1, part2, part3)*3);
        }
    }

    int bloc = n/5;
    for (int nb = 0; nb < 5; nb++) {
        for (int i = 0; i < (1 << bloc); i++) {
            string pattern;
            for (int j = 0; j < bloc; j++) {
                if (i & (1 << j))
                    pattern += s[bloc*nb+j];
            }
            ans = max(ans, get(pattern));
        }
    }
    cout << ans;
}