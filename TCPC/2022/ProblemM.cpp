#include <bits/stdc++.h>
 
#define pb push_back
#define fi first
#define se second
 
typedef long long int ll;
 
using namespace std;
 
const int N = 2e5 + 5, E = 1 << 17;
const int MOD = 1e9 + 7;
 
int t,x;
 
int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x;
        int s=0;
        s+=1;
        int l=-1;
        int r=-1;
        for(int i=2;;i++){
            s+=i;
            if(s>x)
                break;
            long long rhs = 2LL*x;
            if(rhs%i==0){
                long long a = i+ (rhs/i)-1;
                if(a%2==0 && a/2>=1 && (rhs/i - a/2)<=a/2){
                    r=a/2;
                    l = (rhs/i)-r;
                    break;
                }
            }
        }
        if(l==-1){
            cout << -1 << endl;
        }else{
            cout << l << " " << r << endl;
        }
    }
    return 0;
}
