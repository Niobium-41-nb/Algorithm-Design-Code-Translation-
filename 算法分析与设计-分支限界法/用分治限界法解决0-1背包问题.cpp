#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int v[4];
int w[4];
void solve() {
    int W;
    cin >> W;
    int ans = 0;
    
    for(int j = 0;j < 4;j++){
        cin >> w[j] >> v[j];
    }
    for(int i = 0;i < (1 << 4)-1;i++){
        int sum_v = 0;
        int sum_w = 0;
        for(int k = 0;k < 4;k++){
            if(i & (1 << k)){
                sum_v += v[k];
                sum_w += w[k];
            }
        }
        if(sum_w <= W){
            ans = max(ans,sum_v);
        }
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