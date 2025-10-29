#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
struct qj{
    int l,r;
    bool operator < (const qj a) const {
        if(l == a.l)return r < a.r;
        return l < a.l;
    }
};

void solve() {
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<qj>arr;
    for(int i = 1;i <= n;i++){
        int l,r;
        cin >> l >> r;
        arr.push_back({l,r});
    }
    sort(arr.begin(),arr.end());
    int ans = 0;
    for(auto p : arr){
        if(pq.empty()){
            pq.push(p.r);
            ans++;
        }else{
            if(pq.top() > p.l){
                ans++;
                pq.push(p.r);
            }else{
                pq.pop();
                pq.push(p.r);
            
            }
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