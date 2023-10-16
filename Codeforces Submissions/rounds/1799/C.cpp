#include<bits/stdc++.h>
#define ll long long
using namespace std;

string palind(string s) {
    sort(s.begin(), s.end());
    int n = (int) s.size();
    map<char,int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[s[i]]++;
    }
    int nbO = 0;
    char h = '#';
    for (char c = 'a'; c <= 'z'; c++) {
        if (cnt[c]%2 == 1) {
            h = c;
            nbO++;
        }
    }
    if (nbO > 1)
        return "{";
    string as ="";
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 0; i < cnt[c]/2; i++)
            as+= c;
    }
    string k = as;
    reverse(k.begin(), k.end());
    if (h != '#')
        as = as + h + k;
    else
        as = as+k;
    return as;
}

string two(string s) {
    char c = s.back();
    s.pop_back();
    string p = palind(s);
    if (p == "{")
        return p;
    return c+p;
}

string two2(string s) {
    char c = s.back();
    s.front();
    string p = palind(s);
    if (p == "{")
        return p;
    return c+p;
}

string second(string s) {
    char t = '#';
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] != s[i+1]) {
            t = s[i+1];
            break;
        }
    }
    if (t == '#')
        return "{";
    string ch;
    string k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t)
            ch+= s[i];
        else
            k+= s[i];
    }
    reverse(k.begin(), k.end());
    return min(ch+k, k+ch);
}

int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        int n = (int) s.size();
        map<char,int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }
        string s1, s2;
        string hh = "{";
        for (char c = 'a'; c <= 'z'; c++) {
            if (cnt[c]%2 == 0) {
                for (int i = 0; i < cnt[c]/2; i++) {
                    s1 += c;
                    s2 += c;
                }
            }
            else {
                for (int i = 0; i < cnt[c]/2; i++) {
                    s1 += c;
                    s2 += c;
                }
                string h;
                for (char c1 = c+1; c1 <= 'z'; c1++) {
                    for (int i = 0; i < cnt[c1]; i++) {
                        h+= c1;
                    }
                }
                reverse(h.begin(), h.end());
                h = c+h;
                h = min(palind(h), two(h));
                if (h != "{") {
                    reverse(s2.begin(), s2.end());
                    string res = s1 + h + s2;
                    reverse(s2.begin(), s2.end());
                    string res1 = res;
                    reverse(res1.begin(), res1.end());
                    hh = max(res1, res);
                }

                for (char c1 = c+1; c1 <= 'z'; c1++) {
                    for (int i = 0; i < cnt[c1]; i++) {
                        s2 += c1;
                        h+= c1;
                    }
                }
                for (int i = 0; i < cnt[c]%2; i++)
                    s1+= c;

                break;
            }
        }
        reverse(s2.begin(), s2.end());
        string ans = s1+s2;
        string ans1 = ans;
        reverse(ans1.begin(), ans1.end());
        cout << min({hh,palind(s), two(s), max(ans, ans1)}) << '\n';
    }
}