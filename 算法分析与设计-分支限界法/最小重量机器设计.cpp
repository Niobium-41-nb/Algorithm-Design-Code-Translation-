#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,d;
int ans = INF;
vector<vector<int>>w;
vector<vector<int>>c;
vector<int>out;
void dfs(int step,int dep,vector<int>arr){
    int sum_w=0,sum_v=0;
    set<int>st;
    for(int i = 1;i <= dep;i++){
        sum_w += w[i][arr[i]];
        sum_v += c[i][arr[i]];
        st.insert(arr[i]);
    }
    if(st.size() < dep){
        return;
    }
    if(sum_v > d || sum_w > ans){
        return;
    }
    if(dep == n){
        // cout << "sum_w = " << sum_w << ' ';
        // cout << "sum_v = " << sum_v << ' ';
        // for(int i = 1;i <= n;i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << endl;
        ans = sum_w;
        out = arr;
        return;
    }
    for(int i = 1;i <= m;i++){
        arr[dep+1]=i;
        dfs(i,dep+1,arr);
    }
}

void solve() {
    cin >> n >> m >> d;
    w.assign(n+1,vector<int>(m+1,0));
    c.assign(n+1,vector<int>(m+1,0));
    out.assign(n+1,0);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> c[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> w[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        vector<int>arr(n+1,0);
        arr[1] = i;
        dfs(i,1,arr);
    }
    cout << ans << endl;
    for(int i = 1;i <= n;i++){
        cout << out[i] << ' ';
    }
    cout << endl;
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