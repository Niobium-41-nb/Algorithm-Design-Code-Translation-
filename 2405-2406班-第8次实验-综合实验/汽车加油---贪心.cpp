#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int>arr(k+2,0);
    for(int i =1;i <= k+1;i++){
        cin >> arr[i];
    }
    for(int i = 1;i <= k+1;i++){
        if(arr[i] > n){
            cout << "No Solution\n";
            return;
        }
    }
    int now = n;
    int ans = 0;
    for(int i =1;i <= k+1;i++){
        now -= arr[i];
        if(now < 0){
            now = n-arr[i];
            ans++;
        }else{
            
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