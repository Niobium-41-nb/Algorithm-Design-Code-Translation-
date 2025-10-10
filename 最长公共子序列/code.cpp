/*
    最长公共子序列

作者：vanadium-23(Niobium-41-nb)
例题：https://loj.ac/p/6564
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m;
    cin >> n >> m;
    vector<int>a(n+1,0);
    vector<int>b(m+1,0);
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i <= n;i++)cin >> a[i];
    for(int i = 1;i <= m;i++)cin >> b[i];
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            if(a[i] == b[j])dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    cout << dp[n][m];
    return 0;
}