/*
    01背包

作者：vanadium-23(Niobium-41-nb)
例题：https://www.luogu.com.cn/problem/P1048
*/

#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int W,n;
    cin >> W >> n;
    vector<int>v(n+1,0);
    vector<int>w(n+1,0);
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));
    for(int i = 1;i <= n;i++){
        cin >> w[i] >> v[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= W;j++){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0)dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}