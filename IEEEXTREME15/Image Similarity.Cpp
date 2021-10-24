#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 60;

char grid1[N][N];
char grid2[N][N];

int main() {
    int T; cin >> T;
    while (T--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grid1[i][j] = grid2[i][j] = '$';
            }
        }
        int n1,m1; cin >> n1 >> m1;
        int mx = max(n1, m1);
        int ans = 0;
        for (int i = 0; i < n1; i++) {
            string s; cin >> s;
            for (int j = 0; j < m1; j++) {
                grid1[i][j] = s[j];
            }
        }
        int n2,m2; cin >> n2 >> m2;
        for (int i = 0; i < n2; i++) {
            string s; cin >> s;
            for (int j = 0; j < m2; j++) {
                grid2[i][j] = s[j];
            }
        }
        for (int i = 0; i < 4; i++) {
            /// Rotation
            char aux[mx][mx];
            for (int ii = 0; ii < mx; ii++) {
                for (int jj = 0; jj < mx; jj++) {
                    aux[ii][jj] = grid1[jj][mx-ii-1];
                }
            }
            for (int ii = 0; ii < mx; ii++) {
                for (int jj = 0; jj < mx; jj++) {
                    grid1[ii][jj] = aux[ii][jj];
                }
            }
            for (int j = 0; j < 2; j++) {
                ///Flip V
                for (int ii = 0; ii < mx; ii++) {
                    for (int jj = 0; jj < mx; jj++) {
                        aux[ii][jj] = grid1[mx-ii-1][jj];
                    }
                }
                for (int ii = 0; ii < mx; ii++) {
                    for (int jj = 0; jj < mx; jj++) {
                        grid1[ii][jj] = aux[ii][jj];
                    }
                }
                for (int k = 0; k < 2; k++) {
                    /// Flip H
                    for (int ii = 0; ii < mx; ii++) {
                        for (int jj = 0; jj < mx; jj++) {
                            aux[ii][jj] = grid1[ii][mx-jj-1];
                        }
                    }
                    for (int ii = 0; ii < mx; ii++) {
                        for (int jj = 0; jj < mx; jj++) {
                            grid1[ii][jj] = aux[ii][jj];
                        }
                    }
                    /// Matching
                    for (int shiftI = 0; shiftI < 30; shiftI++) {
                        for (int shiftJ = 0; shiftJ < 30; shiftJ++) {
                            int nb1 = 0;
                            for (int ii = 0; ii < 30; ii++) {
                                for (int jj = 0; jj < 30; jj++) {
                                    if (grid1[ii+shiftI][jj+shiftJ] == grid2[ii][jj] && grid2[ii][jj] == '#')
                                        nb1++;
                                }
                            }
                            int nb2 = 0;
                            for (int ii = 0; ii < 30; ii++) {
                                for (int jj = 0; jj < 30; jj++) {
                                    if (grid2[ii+shiftI][jj+shiftJ] == grid1[ii][jj] && grid1[ii][jj] == '#')
                                        nb2++;
                                }
                            }
                            ans = max(ans, nb1);
                            ans = max(ans, nb2);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
