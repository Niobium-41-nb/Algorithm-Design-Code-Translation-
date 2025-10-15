/*
    矩阵乘法

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    vector<vector<int>>b(m+1,vector<int>(k+1,0));
    vector<vector<int>>c(n+1,vector<int>(k+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= k;j++){
            cin >> b[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            for(int p = 1;p <= m;p++){
                c[i][j] += a[i][p] * b[p][j];
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}