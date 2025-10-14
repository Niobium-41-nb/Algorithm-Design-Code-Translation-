/*
    开商店

作者：vanadium-23(Niobium-41-nb)

*/

#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int n,d;
    cin >> n >> d;
    vector<int>arr(n+1,0);
    for(int i = 1;i <= n;i++)cin >> arr[i];
    vector<int>dp(n+1,0);
    int now_max = 0;
    for(int i = 1;i <= n;i++){
        if(i > d){
            now_max = max(now_max,dp[i-d]);
            dp[i] = arr[i] + now_max;
        }else{
            dp[i] = arr[i];
        }
    }
    for(int i = 1;i <= n;i++){
        cout << dp[i] << ' ';
    }
    cout << endl;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans,dp[i]);
    }
    cout << ans << endl;


    return 0;
}

// by vanadium-23