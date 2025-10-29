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
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 1;i <= n;i++){
        int tmp;cin >> tmp;
        pq.push(tmp);
    }
    int ans = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        // cout << a << ' ' << b << endl;
        ans += (a+b);
        pq.push(a+b);
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