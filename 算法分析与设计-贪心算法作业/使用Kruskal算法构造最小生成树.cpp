#include <bits/stdc++.h>
#define int long long
#define LL long long
#define ll long long
using namespace std;

const int N = 2e5+1;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;

struct edge{
    int to;
    int from;
    int val;
    bool operator < (const edge a) const {
        return val > a.val;
    }
};

vector<int> fd(N, 0);
int find(int num) {
    if (fd[num] == num) {
        return num;
    } else {
        return fd[num] = find(fd[num]);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    int ans = 0;
    priority_queue<edge>pq;
    for(int i = 1;i <= m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        pq.push({u,v,w});
    }
    for(int i = 1;i <= n;i++){
        fd[i] = i;
    }
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int u = p.from;
        int v = p.to;
        if(find(u) != find(v)){
            ans+=p.val;
            fd[find(u)] = find(v);
        }else{
            continue;
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