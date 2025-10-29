/*
    矩阵链相乘--动态规划

作者：vanadium-23(Niobium-41-nb)

*/

#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int INF = 1e18;

struct mat{
    int row;
    int col;
};

signed main(){
    int n;
    cin >> n;
    vector<mat>arr(n+1);
    for(int i = 1;i <= n;i++){
        cin >> arr[i].col >> arr[i].row;
    }
    vector<int>p(n+1,0);
    for(int i = 1;i <= n;i++){
        p[i] = arr[i].row;
    }
    p[0] = arr[1].col;
    vector<vector<int>>dp(n+1,vector<int>(n+1,INF));

    // i == j 时，dp[i][j] = 0;
    // i < j 时，dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]p[k]p[j]) 

    for(int len = 1;len <= n;len++){
        for(int i = 1;i <= n && i + len - 1 <= n;i++){
            int j = i + len - 1;
            if(i == j){
                dp[i][j] = 0;
            }
            for(int k = i;k < j;k++){
                dp[i][j] = min(dp[i][j],dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    // for(int i = 1;i <= n;i++){
    //     for(int j = 1;j <= n;j++){
    //         if(dp[i][j] == INF){
    //             cout << "INF ";
    //             continue;
    //         }
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n] << endl;

    return 0;
}

/*
input :

5
5 10
10 4
4 6
6 10
10 2


output :

348


*/