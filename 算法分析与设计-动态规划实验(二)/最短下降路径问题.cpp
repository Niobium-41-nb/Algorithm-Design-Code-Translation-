#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>arr(n+1,vector<int>(n+1,0));
    vector<vector<int>>dp(n+2,vector<int>(n+2,INF));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == 1){
                dp[i][j] = arr[i][j];
            }else{
                dp[i][j] = min({dp[i][j],dp[i-1][j] + arr[i][j],dp[i-1][j-1] + arr[i][j],dp[i-1][j+1] + arr[i][j]});
            }
        }
    }
    int ans = INF;
    for(int i =1;i <= n;i++){
        ans = min(ans,dp[n][i]);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// by vanadium-23