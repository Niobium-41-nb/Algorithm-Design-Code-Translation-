#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int W;
    cin >> W;
    int n = 0;
    vector<int>v(1,0);
    vector<int>w(1,0);
    int tmp_w,tmp_v;
    while(cin >> tmp_w >> tmp_v){
        w.push_back(tmp_w);
        v.push_back(tmp_v);
        n++;
    }
    vector<int>dp(W+1,0);
    for(int i = 1;i <= n;i++){
        for(int p = W;p >= w[i];p--){
            dp[p]=max(dp[p],dp[p-w[i]]+v[i]);
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