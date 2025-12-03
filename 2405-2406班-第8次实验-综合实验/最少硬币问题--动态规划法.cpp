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
    vector<int>arr(n+1,0);
    vector<int>cnt(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i] >> cnt[i];
    }
    int W;
    cin >> W;
    vector<int>dp(W+1,INF);;
    dp[0] = 0;
    for(int i = 1;i <= n;i++){
        for(int p = 1;p <= cnt[i];p++){
            for(int w = W;w >= arr[i];w--){
                dp[w] = min(dp[w],dp[w-arr[i]]+1);
            }
        }
    }
    cout << dp[W] << endl;
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