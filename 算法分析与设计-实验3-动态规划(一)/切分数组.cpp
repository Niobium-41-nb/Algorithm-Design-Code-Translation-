/*
    切分数组

作者：vanadium-23(Niobium-41-nb)

*/

#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a,int b){
    return a * b / gcd(a,b);
}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n+1,0);
    vector<int>dp(n+1,1);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        dp[i] = i;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j >= 1;j--){
            if(gcd(arr[i],arr[j])>1){
                dp[i] = min(dp[i],dp[j-1]+1);
            }
        }
    }
    int ans =0;
    for(int i = 1;i <= n;i++){
        // cout << dp[i] << ' ';
        ans = max(dp[i],ans);
    }
    cout << ans << endl;
    return 0;
}