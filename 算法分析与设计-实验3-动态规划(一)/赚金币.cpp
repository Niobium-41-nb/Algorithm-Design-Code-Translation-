/*
    赚金币

作者：vanadium-23(Niobium-41-nb)

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>arr(n+1,vector<int>(m+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])+arr[i][j];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}