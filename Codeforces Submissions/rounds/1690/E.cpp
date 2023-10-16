#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long pcm(ll a, ll b) {
    return a*b / __gcd(a,b);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,k; cin >> n >> k;
        int a[n];
        ll ans = 0;
        int t[k+1];
        memset(t, 0, sizeof t);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ans+= a[i]/k;
            a[i]%= k;
        }
        sort(a,a+n, greater<int>());
//        for (int i = 0; i < n; i++) {
//            cout << a[i] << ' ';
//        }
//        cout << '\n';

        int j = n-1;
        for (int i = 0; i < n; i++) {
            if (j <= i)
                break;
            while (a[i]+a[j] < k) {
                j--;
                if (j <= i)
                    break;
            }
            if (j > i && a[i]+a[j] >= k) {
                j--;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}