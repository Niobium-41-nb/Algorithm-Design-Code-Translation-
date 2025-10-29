/*
    最长递减子序列

作者：vanadium-23(Niobium-41-nb)

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>arr(n+1,0);
    vector<int>dp(n+1,1);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i-1;j >= 1;j--){
            if(arr[i] < arr[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=  0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,dp[i]);
        // cout << dp[i] << ' ';
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}