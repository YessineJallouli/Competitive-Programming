#include <bits/stdc++.h>
using namespace std;
int M[11][11]={};
int d,c,l,r,ans=1;

int main() {
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    for(int i=0;i<N;++i){
        cin >> d >> l >> r >> c  ;
        if(!d){
            if(c+l-1<=10){
                for(int j=0;j<l;++j){
                    M[r][c+j]++;
                    if(M[r][c+j]>1) ans=0;
                }
            }else
                ans=0;
        }else{
            if(l+r-1<=10){
                for(int j=0;j<l;++j){
                    M[r+j][c]++;
                    if(M[r+j][c]>1) ans=0;
                }
            }else ans=0;
        }
    }
    if(ans)
        cout << "Y \n";
    else
        cout << "N \n";
}