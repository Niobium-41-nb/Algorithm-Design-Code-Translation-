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
    vector<int>arr(n+1,0);
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    sort(arr.begin()+1,arr.end());
    reverse(arr.begin()+1,arr.end());
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 1;i <= k;i++){
        pq.push(0);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int a = pq.top();
        pq.pop();
        ans = max(ans,a+arr[i]);
        pq.push(a+arr[i]);
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